#include <algorithm>

#include <my-lib/math-matrix.h>

namespace Mylib
{
namespace Math
{

// ---------------------------------------------------

void Matrix4d::print ()
{
	auto& m = *this;
	for (uint32_t i=0; i<get_nrows(); i++) {
		for (uint32_t j=0; j<get_ncols(); j++)
			std::cout << m(i, j) << ", ";
		std::cout << std::endl;
	}
}

Matrix4d operator* (const Matrix4d& a_, const Matrix4d& b_)
{
	Matrix4d r_;
	uint32_t i;
	float *a, *b, *r;

	a = a_.get_raw();
	b = b_.get_raw();
	r = r_.get_raw();

	for (i=0; i<16; i++)
			r[i] = 0.0f;

	for (i=0; i<4; i++) {
		for (uint32_t k=0; k<4; k++) {
			const float v = a[i*4 + k];
			for (uint32_t j=0; j<4; j++)
				r[i*4 + j] += v * b[k*4 + j];
		}
	}
	
	return r_;
}

Vector4d operator* (const Matrix4d& m_, const Vector4d& v_)
{
	Vector4d r_;
	float *m, *v, *r;

	m = m_.get_raw();
	v = r_.get_raw();
	r = r_.get_raw();

	for (uint32_t i=0; i<4; i++) {
		r[i] = 0.0f;
		for (uint32_t j=0; j<4; j++)
			r[i] += m[i*4 + j] * v[j];
	}
	
	return r_;
}

// ---------------------------------------------------

} // end namespace Math
} // end namespace Mylib