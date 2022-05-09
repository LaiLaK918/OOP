#pragma once
#include "NV.h"

namespace TienLuong {

	class NVSX :
		public NV
	{
		int soSanPham;
	public:
		NVSX();
		~NVSX();
		void nhap();
		void xuat();
		int64_t tinhLuong();
		string getType();
	};

}