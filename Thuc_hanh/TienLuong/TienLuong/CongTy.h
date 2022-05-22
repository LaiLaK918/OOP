#pragma once
#include "NV.h"
#include "NVQL.h"
#include "NVSX.h"
#include "NVVP.h"

namespace TienLuong {

	class CongTy
	{
		NV** nv;
		int size;
	public:
		CongTy(int _size = 0);
		~CongTy();
		void nhap();
		void xuat();
		int64_t tongLuong();
		NV* timKiem(wstring ten);
		void autoFree(NV** _nv);
	};

}

