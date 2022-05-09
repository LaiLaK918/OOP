#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace TienLuong {

	class NV
	{
	protected:
		wstring ten;
		wstring ngaySinh;
		long luongCoBan;
	public:
		NV();
		virtual ~NV();
		virtual void nhap();
		virtual void xuat();
		virtual int64_t tinhLuong() = 0;
		wstring getTen();
		virtual string getType() = 0;
	};

}