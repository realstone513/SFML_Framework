#include "Utils.h"

random_device Utils::rd;
mt19937 Utils::gen(Utils:: rd());

void Utils::SetOrigin(Text& obj, Origins origin)
{
	FloatRect rect = obj.getLocalBounds();
	Vector2f originpos;
	originpos.x = rect.width * ((int)origin % 3) * 0.5f;
	originpos.y = rect.height * ((int)origin / 3) * 0.5f;
	obj.setOrigin(originpos);	
}

void Utils::SetOrigin(Sprite& obj, Origins origin)
{
	FloatRect rect = obj.getLocalBounds();
	Vector2f originpos;
	originpos.x = rect.width * ((int)origin % 3) * 0.5f;
	originpos.y = rect.height * ((int)origin / 3) * 0.5f;
	obj.setOrigin(originpos);
}

void Utils::SetOrigin(Shape& obj, Origins origin)
{
	FloatRect rect = obj.getLocalBounds();
	Vector2f originpos;
	originpos.x = rect.width * ((int)origin % 3) * 0.5f;
	originpos.y = rect.height * ((int)origin / 3) * 0.5f;
	obj.setOrigin(originpos);
}

void Utils::SetOrigin(Transformable& obj, Origins origin)
{
}

int Utils::Range(int min, int maxExclude)	// 20 40 ������ 20~39 ����.
{
	//0~19 
	return (gen() % (maxExclude - min)) + min;
}

float Utils::RandomRange(float min, int max) //��� max ���Եǰ�.
{
	return min + static_cast<float>(rand()) * static_cast<float>(max - min) / RAND_MAX;
}

float Utils::Magnitude(const Vector2f& vec) //������ ����
{
	return sqrt(vec.x * vec.x + vec.y * vec.y); 
}
float Utils::SqrMagnitude(const Vector2f& vec) //������ ���� ���� ���Ѱ�. ũ�� ��
{
	return (vec.x * vec.x + vec.y * vec.y);
}

Vector2f Utils::Normalize(const Vector2f& vec) //���� ����ȭ
{
	float mag = Magnitude(vec);
	
	if (mag == 0)
		return vec;
	return vec / mag;
}
