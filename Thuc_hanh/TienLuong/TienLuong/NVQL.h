#pragma once
#include "NV.h"

namespace TienLuong {

	class NVQL : public NV
	{
		float heSo;
		long thuong;
	public:
		NVQL();
		~NVQL();
		void nhap();
		void xuat();
		int64_t tinhLuong();
		string getType();
	};

}