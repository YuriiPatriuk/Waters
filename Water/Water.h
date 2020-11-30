#pragma once
class Water
{
public:
	enum class TypeWater {LAKE, OCEAN, SWAMP, SEA};
	const char* getName() const;
	const char* getTypeStr() const;
	const size_t getWidth() const;
	const size_t getLength() const;
	const size_t getMaxDepth() const;
	const size_t getCount() const;

	void setName(const char* name);
	void setWidth(const size_t width);
	void setLength(const size_t length);
	void setMaxDepth(const size_t max);
	void setTypeWater(TypeWater type);
	void print() const;

	explicit Water(const char* name, TypeWater type = TypeWater::LAKE);
	Water();

	const size_t volume() const;
	const size_t square() const;
	static bool compareIdenticalType(const Water& one, const Water& second);
	static int compareSquares(const Water& one, const Water& second);
	static void findTheBigestWater(Water waters[], const size_t& size, const Water::TypeWater& type);

private:
	char* name=nullptr;
	TypeWater type = TypeWater::LAKE;
	size_t width=0;
	size_t length=0;
	size_t maxDepth=0;
	static size_t count;

};

inline  const char* Water::getTypeStr() const
{
	static const char* nameGender[]{ "Lake","Ocean","Swamp", "Sea" };
	return nameGender[(int)type];
}

inline const size_t Water::getWidth() const
{
	return width;
}

inline const size_t Water::getLength() const
{
	return length;
}

inline const size_t Water::getMaxDepth() const
{
	return maxDepth;
}

inline const size_t Water::getCount() const
{
	return count;
}

inline  const char* Water::getName() const
{
	return name;
}

