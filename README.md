# 课程设计2-植物大战僵尸报告

* 选题：标准选题（植物大战僵尸）
* 姓名：马兴越
* 学号：171870660
* 院系：现代工程与应用科学学院
* 编写调试平台：Windows 10, Microsoft Visual Studio 2019

## 提交目录

* `project` 目录，包含完整的Visual Studio工程文件。
* `bin`目录，在Windows 64位编译出的可执行文件。

## 实现摘要

对照课程设计的要求，此处简单列出实现的内容。这里仅仅列出实现结果，而不具体解释实现方法。

### 特色之处

* 植物、僵尸、炮弹的公共抽象基类`Placeable`及类层次。
* 僵尸及护具的继承、聚集混合实现方法，以及魔改组合各种护具和僵尸；带护具僵尸的模版类及mixin设计方法。
* 植物、僵尸工厂类，包括抽象基类和模版的实际类。

### 系统与场地

系统有一时间戳，所以时刻表达都通过**时间戳**，时间表达都以**时钟周期**为单位。。

* 5行8列庭院，自动产生自然光，植物购买（地块选择，种植等），铲子，计分板。
* 按一定逻辑产生僵尸，且有一定的难度递增。
* 提示信息栏，系统时间戳显示

### 植物

植物具有公共接口，都包含生命值，耗费阳光数量，冷却时间等。具体包括下列的植物。对攻击型的植物，单独有`Seed`类表达植物的“炮弹”。这里简单列出所有实现的植物及其基本参数。

特别指出，在设计中，“攻击力”并非是植物的属性，而是植物的炮弹（`Seed`）的属性。但由于设计中的每一种植物都唯一对应到一种炮弹，方便起见，这里也直接列出。

| 名称     | 阳光 | 冷却时间 | 生命值 | 特征周期 | 攻击力 |
| -------- | ---- | -------- | ------ | -------- | ------ |
| 向日葵   | 50   | 5        | 10     | 15       | -      |
| 豌豆射手 | 100  | 5        | 10     | 4        | 2      |
| 寒冰射手 | 175  | 10       | 10     | 4        | 2      |
| 双发射手 | 200  | 10       | 12     | 4, 1     | 2      |
| 西瓜投手 | 300  | 20       | 15     | 5        | 5      |
| 坚果墙   | 50   | 40       | 60     | -        | -      |
| 地刺     | 100  | 20       | -      | 1        | 1      |
| 土豆雷   | 25   | 50       | 10     | 20       | ∞      |
| 火爆辣椒 | 300  | 50       | -      | 2        | ∞      |
| 樱桃炸弹 | 300  | 50       | -      | 2        | ∞      |

### 僵尸及生成逻辑

僵尸大致由两类，单独的一只僵尸（用纯粹的继承实现）和僵尸加上护具（继承+聚集实现）。理论上僵尸可以任意魔改组合，比如说铁桶撑杆僵尸，路障摇旗僵尸之类的。

每500个时钟周期产生一大波僵尸，一大波僵尸总是由摇旗僵尸领头，时长80个时钟周期，这段时间产生僵尸的概率会很高。

一般的僵尸有一个产生相对概率，及一个起始时刻，也就是在该时刻指定的时间戳之后，才可能产生这种僵尸，以体现难度递增。

这里列出所有玩家实际看到的僵尸，也就是包括了僵尸和护具的组合。斜体标出名称的僵尸属于这种类型。所有的僵尸的攻击力（每吃一口的杀伤力）都是2。表中的名称和生命值都已经包括了护具，特征周期是指吃两口之间的间隙。

| 名称           | 生命值 | 速度 | 分值 | 特征周期 | 相对概率 | 起始时刻 |
| -------------- | ------ | ---- | ---- | -------- | -------- | -------- |
| 僵尸           | 10     | 2    | 1    | 3        | 10       | 50       |
| *路障僵尸*     | 20     | 2    | 2    | 3        | 10       | 80       |
| *垃圾桶僵尸*   | 30     | 2    | 3    | 3        | 8        | 100      |
| *铁桶僵尸*     | 40     | 2    | 4    | 3        | 8        | 120      |
| 读报僵尸       | 16     | 2, 6 | 3    | 3        | 6        | 140      |
| *门板僵尸*     | 50     | 2    | 5    | 3        | 6        | 200      |
| 撑杆僵尸       | 20     | 2    | 3    | 3        | 5        | 250      |
| 玩偶盒僵尸     | 20     | 2    | 3    | 3        | 4        | 320      |
| 橄榄球僵尸     | 40     | 3    | 6    | 2        | 6        | 400      |
| *铁桶撑杆僵尸* | 50     | 2    | 6    | 3        | 6        | 800      |
| 摇旗僵尸       | 15     | 3    | 2    | 3        | -        | -        |

## 架构设计

整套系统设计可以大致分为以下几个大块：

* 底层部分，封装基本的控制台交互，包括`Terminal`一个类。
* 场地部分，即庭院和地块，主要包括`Yard`和`Block`两个类，后者强合成于前者中。另有`Position`类，场地上对象和场地之间的桥梁。
* 场地上对象部分。这部分所有的类具有公共的抽象基类`Placeable`，并有以下三个抽象子类。所有的实体类都有这三个类派生而来。
  * 植物部分，抽象基类为`Plant`。
  * 植物炮弹（即种子）部分，抽象基类为`Seed`。植物和炮弹的主要实现类的头文件和实现文件放在`plants`目录下。
  * 僵尸部分，抽象基类为`Zombie`。此外还包括僵尸的护具，抽象基类为`AbstractProtector`，这两部分文件放在`zombies`目录下。
* 控制与交互部分。这部分包括主系统`System`，商店`Shop`，僵尸生成器`ZombieGenerator`以及关联植物/僵尸与生成部分的工厂类。

由于整套系统设计的类比较多，每个类的逻辑实际上都比较简单，但具有较为复杂的关联关系。为了尽可能突出重点，下面的叙述中，针对上面的每个部分（除底层部分外），给出一张不大规范的`UML`类图来反映类之间的关系，而另外用文字或者代码形式描述类定义。

### 控制与交互部分

为了从全局视角，尽量高屋建瓴地阐述，这里最先给出控制与交互部分的设计。

#### `UML`类图

![systemuml](D:\Visual Studio文件\Solutions\Zombie\Zombie\doc\systemuml.png)

#### `System`类

这是系统的中枢。它包含庭院类`Yard`，商店类`Shop`，僵尸生成器`ZombieGenerator`的值，并直接实现以下功能：

* 记录阳光和积分。
* 周期性自动产生阳光。
* 管理所有的`Placeable`对象的指针。
* 主事件循环（函数`mainLoop`）。通过`Sleep()`控制时钟周期，读取键盘输入，并调用购物、铲除植物、退出等函数。

#### 植物工厂

首先给出抽象类的定义中有意义的部分。设计抽象的植物工厂，主要是为了在`Shop`中产生植物时，有一个统一的接口，方便构造数组。后面将看到，`Shop`中与植物工厂的交互都通过这个抽象类完成。

植物所有的[只与购买前后有关的性质]都保存在`PlantFactory`中，这包括冷却时间、耗费阳光数。

```C++
class AbstractPlantFactory
{
protected:
	const int coldPeriod, cost; //冷却时间和耗费阳光。对于一种特定的植物来说，它们是常量。
	const std::string name;
public:
	AbstractPlantFactory(System& sys, int cold, int cost,const std::string& n);
	inline bool available()const;  //是否装载完成
	inline int getRate()const;  //装填完成比例，用于在商店界面显示
	virtual Plant* newInstance() = 0;  //产生植物对象。
};
```

实际的植物工厂是通过继承抽象类的模版类实现的。通过这种方法，无需为每一种植物单独设计工厂类，在增加一种植物时，只需要在`Shop`中增加一行代码即可。继承类的形式很简洁：

```C++
template <typename T>
class PlantFactory :
	public AbstractPlantFactory
{
public:
	PlantFactory(System& sys,int coldPeriod,int cst, const std::string& name);
	virtual T* newInstance()override;
};
```

#### `Shop`类

负责完成用户购物时候的交互部分，所有的植物添加都通过这里完成；同时负责更新庭院以下部分的界面。这里给出一些部分的类定义。

```C++
class Shop
{
	AbstractPlantFactory* factories[N];
public:
	Shop(System& sys);
	void buy();//涉及交互，负责向yard添加植物
	void updateUI();  //每个时钟周期更新界面
private:
	void initUI();
};
```

其中关于`PlantFactory`的初始化形式大概是：

```C++
Shop::Shop(System& sys) :
	factories{
		new PlantFactory<Sunflower>(sys,5,50,"向日葵"),
		new PlantFactory<PeaShooter>(sys,5,100,"豌豆射手"),
		...
	}
...
```

#### 僵尸工厂

僵尸工厂的设计思路和继承结构和植物工厂完全类似，这里不再赘述。只是与构造有关的具体数据不大相同。僵尸工厂类保存的数据是僵尸产生的相对概率，和该种僵尸可能开始产生的时间点。

#### `ZombieGenerator`类

与`Shop`负责产生植物实例类似，这个类负责产生僵尸的实例。部分的类定义为

```C++
class ZombieGenerator
{
	static const int GroupInterval = 500, GroupLength = 80; //“一大波僵尸”的周期和时长
	AbstractZombieFactory* factories[N];
	AbstractZombieFactory* directFactory;  //摇旗僵尸
public:
	void generate();  //接口方法，由System直接调用
private:
	double rate()const;  //返回当前时钟周期产生僵尸的概率
	int truns()const;
};
```

僵尸产生的方法是：每个时钟周期有`turns()`次机会产生僵尸，

> 可以理解为，每个周期掷`turns()`次骰子。在非“一大波”的状态，`turns()`总是1；在一大波的状态，第`n`轮中`turn()`返回值为`n`，最大为`5`。

每一次机会中有`rate()`的概率产生僵尸，

> 在非“一大波”的状态下，`rate()`一般返回0.5；特别的，在游戏开始后第一大波僵尸到达前，这个概率从`0.1`开始线性地增加到`0.5`。在“一大波”的状态下，`rate()`总是返回0.90. 这就是说，第5轮及之后的一大波僵尸中，每一个时钟周期将会期望产生4.5只僵尸。

如果确定产生僵尸，则产生各种当前可能产生的僵尸，按照相对概率产生。每一轮的僵尸生成之间是独立的。

概括地说，游戏难度的渐进性体现在：

* 每一种僵尸只能在一定的时间点之后才能产生。
* 第一轮之前，产生僵尸的概率是随时间线性增加的。
* 在前5轮中，每一大波的僵尸的数量是递增的。

### 场地部分

#### `UML`类图

![场地类图](D:\Visual Studio文件\Solutions\Zombie\Zombie\doc\yarduml.png)

#### `Block`类

每个`Block`对象指庭院中的一个地块，它由控制台中一定的行列数构成。

`Block`中分类别保存了该地块上植物，所有当前在该地块上的僵尸和炮弹的指针。当僵尸（炮弹）走入（飞入）地块时，将其指针加入；离开时取出。每个时钟周期，`Block`更新地块上要显示的内容。

#### `Yard`类

庭院类，可以理解成`ROWS*COLS`个`Block`的组合，持有他们的值类型对象。负责更新界面。每个时钟周期刷新一次界面。

#### `Position`类

位置类，描述某一个特定的场地上对象当前的位置。对于每一个场地上对象（`Placeable`对象），我们约定其位置由行、列表示，其中行只精确到庭院上抽象的一行，而列精确到具体的字符位置（或理解为控制台的“像素”，程序中用`colpix`区分）。重要的接口方法是

```C++
Block* Position::target();
```

指出当前位置对应庭院上的地块。

### 场地上对象部分

由于这部分的类太多，如果表示在一张类图上过于凌乱，所以分成多张来表现。首先给出的是总体的设计。

![placeable](D:\Visual Studio文件\Solutions\Zombie\Zombie\doc\placeableuml.png)

#### `Placeable`基类

前面已经提到，所有的植物、僵尸、炮弹，都可以理解为“放”在场地上的，它们都具有一个位置，都要放置和移出，每个时钟周期都要更新一次。根据这些特点，抽象出基类`Placeable`。主要的定义如下：

```C++
class Placeable
{
protected:
	Position position;
public:
	static int timestamp;  //系统的时间戳是由这里维护的
	virtual void update() = 0;  //每个周期的更新
	virtual void place() = 0;
	virtual void remove() = 0;
	Block* getBlock();
	void setPosition(int row, int colpix);
};
```

在实际编程中，由于`Block`在处理植物、僵尸、炮弹时，使用了不同的逻辑分别管理，所以`place()` `remove()`方法都是分别实现的。这个抽象的基类除了逻辑上的意义外，目前只有一处直接的作用，就是在`System`中保存了所有`Placeable`对象的指针，在每个时钟周期，通过这里调用`update()`函数完成更新。

#### 植物部分

这部分的代码和实现都在`plants`子目录下；其中`plants.h`中包含了所有植物的头文件。

为了利用动态绑定的机制，大多数的每一种植物和僵尸的常量都是通过抽象内联函数实现的，这样可以在基类定义时写出尽量多的逻辑，以减少重复的代码。虽然大体上还是按照一个实现类一套`.h/.cpp`文件安排的，但大多数的实体类的实现文件实际上都没多少代码。`Plant`类的主要定义如下。

```C++
class Plant:
	public Placeable
{
protected:
	int hp;  //当前生命值
	virtual inline int initHp()const = 0;  //初始生命值
public:
	Plant(System& sys);
	void place();  //放置。放置到地块中，然后加入到System控制中。
	void remove(); //从Yard中删除，并从System中删除。
	virtual inline bool eatable()const { return true; } //地刺不能被吃, 其他的基本上都是true
	void eaten(int dh); //被吃时调用。如果hp到了0，则自动remove。
	void setBlock(int row, int col); //对植物来说其实不存在具体的列，设置到指定的行就可以了。
	virtual inline bool hasStatus()const { return true; }  //是否有状态，也就是界面中植物名称下面的一行字
	virtual inline std::string getStatus()const;
	virtual inline std::string toString()const = 0;//约定不超过一格宽度
};
```

这里举出几个较有代表性的例子来说明具体的实现。

##### 豌豆射手

有一个特殊函数：

```C++
virtual void shoot();
```

每次执行`update()`时，检查是否到了发射的时间，如果到了则调用这个函数来发射豌豆。

在其子类`IceShooter`中，只修改了这个函数，使得发射的炮弹不一样；而在子类`DoubleShooter`中，只修改了`update()`函数而直接利用`PeaShooter`中实现的`shoot()`函数。

##### 樱桃炸弹

这是个无状态的植物（即：`hasStatus()`返回`false`）。在放置后2个时钟周期即爆炸；爆炸时，遍历8邻域，调用其中所有僵尸的`remove()`函数，同时将地块状态设置为“全部爆炸”状态。

#### 炮弹部分

以射击、投掷方式攻击的植物的攻击由炮弹来实现，它们是`Seed`的子类。接口如下。

```C++
class Seed :
	public Placeable
{
public:
	virtual void place()override;
	virtual void remove()override;
	inline virtual int damage()const = 0;  //伤害值
	inline virtual int speed()const = 0;   //速度
	virtual void explode();  //爆炸，默认是对格子里的僵尸产生damage()的伤害。负责调用remove。
	virtual void update();   //更新位置，如果遇到僵尸调用爆炸
	virtual void attactZombie(Zombie* zombie);  //对爆炸地块内的每一只僵尸调用
	virtual inline char toChar()const=0;
};
```

这里直接给出了`update()`的实现。在默认的实现中，如果当前所处地块有僵尸，则执行`explode()`，即爆炸；爆炸过程，对地块中所有的僵尸调用`attactZombie()`方法。这样设计的目的是让子类重新实现时，有更大的发挥空间。在本程序中，`Seed`共有三个子类，即`PeaSeed`，`IceSeed`和`Watermelon`。由于西瓜是群伤，对上下格子里的僵尸也有作用，所以重写了`explode()`函数，但`update()`和`attackZombie()`都不用重写。

与植物、僵尸两类实现`toString()`不同，为了实现飞行运动的效果，`Seed`类实现的是`toChar()`方法，来向控制台输出。实际实现中，普通豌豆为`o`（小写字母），冰豌豆为`*`，西瓜为`O`（大写字母）。

#### 僵尸部分

首先给出僵尸部分的类图。

![zombies](D:\Visual Studio文件\Solutions\Zombie\Zombie\doc\zombiesuml..png)



相比其他两个平行的类，僵尸类实现了更多的方法。如前所述，大多数的常数或者几乎是常数的属性

> 按：“几乎是常数”指的是`speed()`和`biteInterval()`，它们一般只有两个值，就是正常时和被冰冻豌豆打中后减慢时。

都是用`virtual inline int xxx() const;`这样的函数实现的，为的是利用动态绑定机制。

```C++
class Zombie:
	public Placeable
{
protected:
	int hp;  //生命值
	virtual inline int damage()const = 0;  //啃一口的破坏力
	virtual inline int speed()const = 0;   //移动速度，正常都是负数
	virtual inline int initHp()const = 0;  //初始生命值
	virtual inline int score()const = 0;   //被打死后的得分
	virtual inline int getBiteInterval()const = 0;  //啃两口之间的间隙
public:
	void move(int dcol, int drow = 0);  //每个时钟周期移动一次
	void place();
	void remove();
	virtual void eat(Plant* plant);  //啃一口植物
	virtual void update();
	virtual void attacked(int dh);  //被炮弹打中。打死时自动remove
	virtual inline std::string getStatus()const;
	virtual inline std::string toString()const = 0;
	virtual void slowDown(int tm);  //被冰豌豆打中时减慢速度
};
```

实际的僵尸类是采用聚集和继承混合的办法实现的。下面说明`ProtectedZombie`（带护具的僵尸）类，而其他的类都是平凡的，只用到了简单的继承，无需赘述。

##### 护具与护具僵尸

这里将所有的，只具有保护功能的道具抽象成Protector类，这包括路障、铁桶、门板等。而带有其他功能或者用途的道具，例如撑杆僵尸的杆子，小丑僵尸的玩偶盒，将其简单的归结为僵尸本身的特殊性质，从而用继承而不是聚集来实现。所有护具类的抽象基类是：

```C++
class AbstractProtector {
protected:
	int value;  //相当于生命值
public:
	virtual inline int initValue()const = 0;  //初始生命值
	virtual inline std::string toString()const = 0;
	virtual inline int score()const = 0;
	void attacked(int dv);//dv>0即可
	inline bool isActive()const;  //是否还有效。无效之后，相当于变成了普通的僵尸。
};
```

程序中一共实现了四种护具，

```C++
class RoadBlock;  //路障，生命值10
class CR200J;     //垃圾桶，生命值20 (类名是一种垃圾桶的型号😏x
class Bucket;     //铁桶，生命值30
class Door;       //铁门板，生命值50
```



现在来说明护具僵尸类。这里用到了Mixin的方法来设计，是一个模版类。基础僵尸和护具都由模版类参数指定。

> ( 竟然从*Thinking in Java* 上学到了C++的奇淫巧技

```C++
template <typename BaseZombie,typename Protector>
class ProtectedZombie:
	public BaseZombie 
{
	Protector protector;
public:
	ProtectedZombie(System& system);
	virtual std::string toString()const override;
	virtual std::string getStatus()const override;
	virtual inline int score()const override;
	virtual void attacked(int dh)override;
};
```

这样设计的目的时统一各种不同的护具僵尸。路障僵尸、铁桶僵尸等的逻辑都差不多，除了生命值、得分、显示文字不同外，其实都差不多，完全没必要分别写一个类。如此设计，则在构建僵尸时，只需要一行代码就可以指定，例如（这部分代码见`ZombieGenerator.cpp`）

```C++
new ZombieFactory<ProtectedZombie<NormalZombie,RoadBlock>>(system,10,80)
```

当然，作为副产品，也完全可以魔改组合出一些奇怪的僵尸，同样只需要一行代码即可实现，比如说撑杆摇旗僵尸，垃圾桶玩偶盒僵尸之类的。程序中用了一种，权当个玩笑吧，

```C++
new ZombieFactory<ProtectedZombie<VaultZombie,RoadBlock>>(system,6,800),  //路障撑杆僵尸
```

这种设计带来了一些新的问题和特性，这里列出来：

* 积分。我们规定，打败一只受保护僵尸的积分，等于基础僵尸的积分加上护具的积分。
* 受攻击时的行为。我们规定，当护具有效时，先打击护具；当护具有效值`value`归0后，再打击僵尸本身。
* 在程序中的显示。当护具有效时，显示格式为“护具名称+僵尸名称”，例如“垃圾桶僵尸”；当护具无效时，护具僵尸退化为基础僵尸（`BaseZombie`），此时显示名称变为基础僵尸的名称。这与原版的植物大战僵尸游戏是一致的，也就是游戏中铁桶僵尸的帽子被打掉后，和普通僵尸没有什么区别。

### 控制台交互



