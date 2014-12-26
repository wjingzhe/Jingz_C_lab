#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高
#define NULL 0 //空为0
#define MAXSIZE 20
#define INCREAMENT 10
typedef int Status;
typedef struct BSTNode
{
	float data;
	int bf;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
void R_Rotate(BSTree &p);
void L_Rotate(BSTree &p);
void LeftBalance(BSTree &T);
void RightBalance(BSTree &T);
void ClearTree(BSTree &T)//假如T不为空，则销毁T
bool InsertAVL(BSTree &T,float e,bool &taller);
	//若在平衡的二叉排序树T中部存在和e有相同关键字的结点，则插入一个数据元素
	//为e的新节点，并返回1，否则返回0.若因插入而使二叉排序树失去平衡，则作平衡旋转处理
	//布尔变量taller反映T长高与否

bool SearchAVL(BSTree T,float key,BSTree f,BSTree &p);
//查找平衡二叉树中与key相等的元素结点,查找成功则返回1，p为该位置指针，否则返回0，p为其应该挂接的位置

int GetHeightAVL(BSTree T);//求平衡二叉树的深度,返回高度

int DeleteAVL(BSTree &T,float key,bool &lower);//删除平衡二叉树中与key相等的元素结点，删除成功返回1，不成功返回0

int TraverseAVL(BSTree T,int i); //以中序遍历访问平衡二叉树T，并进行树状显示输出，成功返回1

int DispAVL(BSTree T,int i); //以凹凸表（上右子树，下左子树的形式）打印显示非空平衡二叉树，成功返回1

bool AVLEmpty(BSTree T); //若T为空树，则返回true，否则返回false

bool IsaAVL(BSTree T);//判定是否为一棵平衡二叉树,是则返回true，否则返回false

bool ClearTree(BSTree &T); //清空一个树，变成空树，并返回true

bool CreateAVL(BSTree &T); // 清空原树，供演示
bool CreateAVL(BSTree &T,int n)//只有树根T作为参数,则随机生成一棵含有n个有效数据的AVL树，供演示，返回true
bool CreateAVL(BSTree &T,float *a,int n);   //参数有树根、数组名、数组长度，构建一棵AVL树,全部元素均为插入则返回false

bool InOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//正常访问返回true，当出现某个节点访问失败则返回false，并终止访问。
float* InOrderAVL(BSTree T,bool (*Visit)(float e),int &n); //中序遍历，正常访问返回一个float型数组，并打印平衡二叉树排序序列。
float* InOrderAVL(BSTree T,int &n); //中序遍历，正常访问返回一个float型数组，数组长度。

bool PreOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//正常访问返回true，当出现某个节点访问失败则返回false，并终止访问。

float* PreOrderAVL(BSTree T,bool (*Visit)(float e),int &n); //前序遍历，正常访问返回一个float型数组，打印显示平衡二叉树的数据元素
float* PreOrderAVL(BSTree T,int &n);  //前序遍历，正常访问返回一个float型数组，数组长度

bool PostOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i);
//正常访问返回true，当出现某个节点访问失败则返回false，并终止访问。

float* PostOrderAVL(BSTree T,bool (*Visit)(float e),int &n); //后序遍历，正常访问返回float数组，并打印平衡二叉树排序序列。
float* PostOrderAVL(BSTree T,int &n);   //后序遍历，正常访问返回float数组，以及数组长度


BSTree MergeAVL(BSTree &p,BSTree &q); // 合并两棵平衡二叉树,返回树根p
BSTree DistributeAVL(BSTree &p); //分裂后的的森林有两棵树，都是平衡二叉树，原树根指向原树的右子树，原树的左子树作为返回值

bool PrintfBST(float e);//访问该节点，并存放于数组a中，返回true，内存申请失败则返回false
bool Nothing(float e); //空访问，return true;