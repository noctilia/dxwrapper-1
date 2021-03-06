#pragma once

#define CINTERFACE

#include <d3d.h>

#include "Common/VtableVisitor.h"

template <>
struct VtableForEach<IDirect3DVtbl>
{
	template <typename Vtable, typename Visitor>
	static void forEach(Visitor& visitor)
	{
		VtableForEach<IUnknownVtbl>::forEach<Vtable>(visitor);

		DD_VISIT(Initialize);
		DD_VISIT(EnumDevices);
		DD_VISIT(CreateLight);
		DD_VISIT(CreateMaterial);
		DD_VISIT(CreateViewport);
		DD_VISIT(FindDevice);
	}
};

template <>
struct VtableForEach<IDirect3D2Vtbl>
{
	template <typename Vtable, typename Visitor>
	static void forEach(Visitor& visitor)
	{
		VtableForEach<IUnknownVtbl>::forEach<Vtable>(visitor);

		DD_VISIT(EnumDevices);
		DD_VISIT(CreateLight);
		DD_VISIT(CreateMaterial);
		DD_VISIT(CreateViewport);
		DD_VISIT(FindDevice);
		DD_VISIT(CreateDevice);
	}
};

template <>
struct VtableForEach<IDirect3D3Vtbl>
{
	template <typename Vtable, typename Visitor>
	static void forEach(Visitor& visitor)
	{
		VtableForEach<IUnknownVtbl>::forEach<Vtable>(visitor);

		DD_VISIT(EnumDevices);
		DD_VISIT(CreateLight);
		DD_VISIT(CreateMaterial);
		DD_VISIT(CreateViewport);
		DD_VISIT(FindDevice);
		DD_VISIT(CreateDevice);
		DD_VISIT(CreateVertexBuffer);
		DD_VISIT(EnumZBufferFormats);
		DD_VISIT(EvictManagedTextures);
	}
};

template <>
struct VtableForEach<IDirect3D7Vtbl>
{
	template <typename Vtable, typename Visitor>
	static void forEach(Visitor& visitor)
	{
		VtableForEach<IUnknownVtbl>::forEach<Vtable>(visitor);

		DD_VISIT(EnumDevices);
		DD_VISIT(CreateDevice);
		DD_VISIT(CreateVertexBuffer);
		DD_VISIT(EnumZBufferFormats);
		DD_VISIT(EvictManagedTextures);
	}
};
