#ifndef __MYMATH__
#define __MYMATH__

namespace MyMath
{
	int GetRandInteger(int from, int to);


	struct Vector2D
	{
		typedef double Type;

		Type x, y;

		Vector2D() : x(0.0), y(0.0) {}
		Vector2D(Type x, Type y) : x(x), y(y) {}

		//Set x,y 0.0
		inline void Zero();

		inline bool IsZero() const;
		inline Type Length() const;
		inline Type LengthNoSqrt() const;
		inline void Normalize();
		
		inline Type Dot(const Vector2D& v2) const;
		
		//v2가 현재 벡터의 시계방향에 존재하면 양수, 반시계면 음수 반환
		//inline int Sign(const Vector2D& v2) const;

		//수직벡터 반환
		inline Vector2D		Perp() const;
		
		inline void			Truncate(Type Max);
		inline Type			Distance(const Vector2D& v2) const;
		inline Type			DistanceNoSqrt(const Vector2D& v2) const;
		inline Vector2D		GetReverse() const;

		const Vector2D& operator+=(const Vector2D& rhs);
		const Vector2D& operator-=(const Vector2D& rhs);
		const Vector2D& operator*=(const Vector2D& rhs);
		const Vector2D& operator/=(const Vector2D& rhs);
		bool operator==(const Vector2D& rhs) const;
		bool operator!=(const Vector2D& rhs) const;
	};


} //namespace MyMath

#endif //__MYMATH__
