#include "PCStaticVertexBuffer.h"

cdc::PCStaticVertexBuffer::PCStaticVertexBuffer(PCStaticPool* pStaticPool) : PCInternalResource(), m_allocation()
{
	m_pStaticPool = pStaticPool;
	m_numVertices = 0;
	m_stride = 0;
	m_baseVertIndex = 0;
	m_pVertexData = nullptr;;
	m_ownsData = false;
}

void cdc::PCStaticVertexBuffer::Create(void* pVertexData, D3DVERTEXELEMENT9* pVertexElements, unsigned int stride, unsigned int numVertices)
{
	OnConstruct();
}

unsigned int cdc::PCStaticVertexBuffer::GetBaseVertexIndex()
{
	return m_baseVertIndex;
}

IDirect3DVertexBuffer9* cdc::PCStaticVertexBuffer::GetD3DVertexBuffer()
{
	return m_allocation.m_buffer;
}

IDirect3DVertexDeclaration9* cdc::PCStaticVertexBuffer::GetD3DVertexDeclaration()
{
	return nullptr;
}

unsigned int cdc::PCStaticVertexBuffer::GetNumVertices()
{
	return m_numVertices;
}

unsigned __int16 cdc::PCStaticVertexBuffer::GetStride()
{
	return m_stride;
}

bool cdc::PCStaticVertexBuffer::OnCreateDevice()
{
	m_pStaticPool->AllocVertices(&m_allocation, m_stride, m_numVertices);

	return true;
}

void cdc::PCStaticVertexBuffer::OnDestroyDevice()
{
}