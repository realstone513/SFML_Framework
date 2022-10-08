#include "Utils.h"

random_device Utils::rd;
mt19937 Utils::gen(Utils::rd());

void Utils::SetOrigin(Text& obj, Origins origin)
{
	SetOrigin(obj, origin, obj.getLocalBounds());
}

void Utils::SetOrigin(Sprite& obj, Origins origin)
{
	SetOrigin(obj, origin, obj.getLocalBounds());
}

void Utils::SetOrigin(Shape& obj, Origins origin)
{
	SetOrigin(obj, origin, obj.getLocalBounds());
}

void Utils::SetOrigin(Transformable& obj, Origins origin, FloatRect rect)
{
	Vector2f originPos(rect.width, rect.height);
	originPos.x *= ((int)origin % 3) * 0.5f;
	originPos.y *= ((int)origin / 3) * 0.5f;
	obj.setOrigin(originPos);
}

int Utils::Random(int min, int maxExclude)
{
	return (gen() % (maxExclude - min)) + min;
}

float Utils::Random(float min, int maxInclude)
{
	float div = maxInclude - min + 1.0f;
	std::uniform_real_distribution<> dist(min, maxInclude);
	return dist(gen);
}

float Utils::Magnitude(const Vector2f& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y); 
}
float Utils::SqrMagnitude(const Vector2f& vec)
{
	return (vec.x * vec.x + vec.y * vec.y);
}

Vector2f Utils::Normalize(const Vector2f& vec)
{
	float mag = Magnitude(vec);
	
	if (mag == 0)
		return vec;
	return vec / mag;
}

float Utils::Lerp(float A, float B, float Alpha)
{
	return A * Alpha + B * (1 - Alpha);
}

Vector2f Utils::Lerp(Vector2f A, Vector2f B, float Alpha)
{
	return A * Alpha + B * (1 - Alpha);
}