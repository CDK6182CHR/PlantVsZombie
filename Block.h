/*
�����ϵ�һ���ؿ顣�������±���ʣ���Ч���0��ʼ��
 */
#pragma once
#include <list>
#include <vector>
#include <string>

enum class BlockStatus
{
	Normal,
	WholeExploded,
	BottomExploded,
};

class Plant;
class Zombie;
class Seed;

class Block
{
	std::list<Zombie*> zombies;
	std::string* itemStrings;
	std::list<Seed*> seeds;
	BlockStatus status;
	Plant* plant;
	int row, col;
public:
	static const int PIXES_PER_COL = 13, //ÿһ���Ӧ��������������߽硣
		PIXES_PER_ROW = 5,//ÿһ���Ӧ�������������ϱ߽硣
		CENTER_ROW = 2;
	Block();//Ĭ�Ϲ��죬����������þ������
	void setStatus(BlockStatus s);
	void init(int r, int c);//����
	void addZombie(Zombie* zombie);
	void removeZombie(Zombie* zombie);
	void addSeed(Seed* seed);
	void removeSeed(Seed* seed);
	void setPlant(Plant* plant);
	Plant* currentPlant();
	std::list<Zombie*>& getZombies();
	int zombieCount()const;
	void removePlant();
	std::string getBlockText(int row)const;//���ص�row����ʾ�����֡�row��1��PIXES_PER_ROW֮�䡣
	void update();
	bool operator==(const Block& an)const; //��Ҫ��ʵ��
	inline int getRow()const { return row; }
	inline int getCol()const { return col; }
	~Block();
private:
	void updateStrings();
	int localColpix(int globalColpix)const;//��ȫ�ֵ���ת��Ϊ��ǰ���ӵ��кš�
};

