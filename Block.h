/*
场地上的一个地块。用数组下标访问，有效域从0开始。
 */
#pragma once
#include <list>
#include <vector>
#include <string>

class Plant;
class Zombie;
class Seed;

class Block
{
	std::list<Zombie*> zombies;
	std::string* itemStrings;
	std::list<Seed*> seeds;
	Plant* plant;
	int row, col;
public:
	static const int PIXES_PER_COL = 11, //每一格对应的列数。包含左边界。
		PIXES_PER_ROW = 5,//每一格对应的行数，包含上边界。
		CENTER_ROW = 2;
	Block();//默认构造，构造后再设置具体参数
	void init(int r, int c);//必须
	void addZombie(Zombie* zombie);
	void removeZombie(Zombie* zombie);
	void addSeed(Seed* seed);
	void removeSeed(Seed* seed);
	void setPlant(Plant* plant);
	Plant* currentPlant();
	std::list<Zombie*>& getZombies();
	int zombieCount()const;
	void removePlant();
	std::string getBlockText(int row)const;//返回第row行所示的文字。row在1至PIXES_PER_ROW之间。
	void update();
	bool operator==(const Block& an)const; //需要才实现
	~Block();
private:
	void updateStrings();
	int localColpix(int globalColpix)const;//将全局的列转换为当前格子的列号。
};

