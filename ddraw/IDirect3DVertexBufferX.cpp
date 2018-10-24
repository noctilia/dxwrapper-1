/**
* Copyright (C) 2018 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "ddraw.h"

HRESULT m_IDirect3DVertexBufferX::QueryInterface(REFIID riid, LPVOID * ppvObj, DWORD DirectXVersion)
{
	Logging::LogDebug() << __FUNCTION__;

	return ProxyQueryInterface(ProxyInterface, riid, ppvObj, GetWrapperType(DirectXVersion), WrapperInterface);
}

void *m_IDirect3DVertexBufferX::GetWrapperInterfaceX(DWORD DirectXVersion)
{
	switch (DirectXVersion)
	{
	case 1:
		if (!UniqueProxyInterface.get())
		{
			UniqueProxyInterface = std::make_unique<m_IDirect3DVertexBuffer>(this);
		}
		return UniqueProxyInterface.get();
	case 7:
		if (!UniqueProxyInterface7.get())
		{
			UniqueProxyInterface7 = std::make_unique<m_IDirect3DVertexBuffer7>(this);
		}
		return UniqueProxyInterface7.get();
	default:
		Logging::Log() << __FUNCTION__ << " Error, wrapper interface version not found: " << DirectXVersion;
		return nullptr;
	}
}

ULONG m_IDirect3DVertexBufferX::AddRef()
{
	Logging::LogDebug() << __FUNCTION__;

	return ProxyInterface->AddRef();
}

ULONG m_IDirect3DVertexBufferX::Release()
{
	Logging::LogDebug() << __FUNCTION__;

	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		if (WrapperInterface)
		{
			WrapperInterface->DeleteMe();
		}
		else
		{
			delete this;
		}
	}

	return x;
}

HRESULT m_IDirect3DVertexBufferX::Lock(DWORD dwFlags, LPVOID * lplpData, LPDWORD lpdwSize)
{
	Logging::LogDebug() << __FUNCTION__;

	return ProxyInterface->Lock(dwFlags, lplpData, lpdwSize);
}

HRESULT m_IDirect3DVertexBufferX::Unlock()
{
	Logging::LogDebug() << __FUNCTION__;

	return ProxyInterface->Unlock();
}

HRESULT m_IDirect3DVertexBufferX::ProcessVertices(DWORD dwVertexOp, DWORD dwDestIndex, DWORD dwCount, LPDIRECT3DVERTEXBUFFER7 lpSrcBuffer, DWORD dwSrcIndex, LPDIRECT3DDEVICE7 lpD3DDevice, DWORD dwFlags)
{
	Logging::LogDebug() << __FUNCTION__;

	if (lpSrcBuffer)
	{
		lpSrcBuffer = static_cast<m_IDirect3DVertexBuffer7 *>(lpSrcBuffer)->GetProxyInterface();
	}
	if (lpD3DDevice)
	{
		lpD3DDevice = static_cast<m_IDirect3DDevice7 *>(lpD3DDevice)->GetProxyInterface();
	}

	return ProxyInterface->ProcessVertices(dwVertexOp, dwDestIndex, dwCount, lpSrcBuffer, dwSrcIndex, lpD3DDevice, dwFlags);
}

HRESULT m_IDirect3DVertexBufferX::GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC lpVBDesc)
{
	Logging::LogDebug() << __FUNCTION__;

	return ProxyInterface->GetVertexBufferDesc(lpVBDesc);
}

HRESULT m_IDirect3DVertexBufferX::Optimize(LPDIRECT3DDEVICE7 lpD3DDevice, DWORD dwFlags)
{
	Logging::LogDebug() << __FUNCTION__;

	if (lpD3DDevice)
	{
		lpD3DDevice = static_cast<m_IDirect3DDevice7 *>(lpD3DDevice)->GetProxyInterface();
	}

	return ProxyInterface->Optimize(lpD3DDevice, dwFlags);
}

HRESULT m_IDirect3DVertexBufferX::ProcessVerticesStrided(DWORD dwVertexOp, DWORD dwDestIndex, DWORD dwCount, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwSrcIndex, LPDIRECT3DDEVICE7 lpD3DDevice, DWORD dwFlags)
{
	Logging::LogDebug() << __FUNCTION__;

	if (lpD3DDevice)
	{
		lpD3DDevice = static_cast<m_IDirect3DDevice7 *>(lpD3DDevice)->GetProxyInterface();
	}

	return ProxyInterface->ProcessVerticesStrided(dwVertexOp, dwDestIndex, dwCount, lpVertexArray, dwSrcIndex, lpD3DDevice, dwFlags);
}
