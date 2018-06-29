# 期末项目——Simple Circuit
# 主要实现功能
- 门电路的连接，移除等操作。
- 用户交互
- 连接完成后，可以给定输入来获取输出
- 检查环异常（连接前/后？）
- 与或非门

# 具体实现
- 先连接，使用邻接矩阵来记录各门电路的连接
- 环异常检查：（正常的应该是irreflexive & asymmetric
- 增加门电路的输入：使用运算符重载，加号
- 使用circuit control管理所有创建的门，邻接矩阵记录每个门的连接方式，同时记录一共创建了多少个门，在创建每一个门的时候，每个门都有独一无二的编号
- 

# 类
```
class circuitControl{
    private:
    circuitControl* instance;
    bool matrix[size][size];//邻接矩阵
    door* head;
    door* tail;
    int doorNumber;//门的数量,决定矩阵的大小，create的时候改变
    public:
    void print();//列全为零 则是要给input的，行全为零，则是最终输出的。对于那些没有输入和输出的。。。emm
    void create();
    void list();//列出create了的总数
    void connect();//改变邻接矩阵的值
    void execute();
    void setInput();
};
//问题来了，如何将邻接矩阵和创建的门一一对应？->按照创建的先后顺序？
class door{
    private:
    string name;
    int type;
    int id;//a specific id
    protected:
    bool* input;
    bool output;
    public:
    door();//问题：虚基类需要构造函数嘛？->应该的吧(设定好private里面的？)
    virtual ~door()
    virtual int getType()=0;//获取这是一个什么门
    virtual void setInput()=0;
    virtual bool getOutput()=0;
    virtual bool* getInput()=0;
    virtual door& operator=(door& d)=0;
    virtual door& operator+(door& d)=0;
};
class doorAnd:public door{
    private:
    public:
};
class doorOr:public door{
    private:
    public:
};
class doorNot:public door{
    private:
    public:
}
```

# 操作顺序
- 首先create，再connect，（全部在邻接矩阵上操作）
- execute（此时检查是否有环异常），若有环异常则不运行（使用邻接矩阵检查）
- 没有任何的异常，则开始按顺序运行（从得到输入的门开始，然后是它接着的门，以此类推）
- //使用BFS来推进运行过程（给灰色节点的succesor加输入）->好像不行
- 获取了所有输入的门才能有输出（拓扑排序？求矩阵的传递闭包，对传递闭包进行拓扑排序
- 获取输出