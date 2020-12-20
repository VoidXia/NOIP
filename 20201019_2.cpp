#include<iostream>
#include<iomanip>
using namespace std;

template <class elemType>
class seqList{
    private:
        elemType *data;
        int currentLength;
        int maxSize;
    public:
        seqList(int initSize=10){
            data=new elemType[initSize];
            maxSize=initSize;
            currentLength=0;
        }
        ~seqList(){delete[]data;}
        friend ostream& operator<<(ostream& os, const seqList& cp){//重载<<
            for(int i=0;i<cp.currentLength;i++)os<<cp.data[i]<<' ';
            return os;
        }
        void doublespace(){
            elemType *tmp = data;  
            data = new elemType[2 * currentLength];  
            for (int i = 0; i < currentLength; i++) data[i] = tmp[i];  
            maxSize = 2 * currentLength;  
            delete [] tmp;  
        }
        void insert(const elemType &aa){
            if(currentLength+1>=maxSize)doublespace();
            data[currentLength]=aa;
            currentLength++;
        }
        elemType del(){
            //data[currentLength]=aa;
            currentLength--;
            return data[currentLength];
        }
        elemType getnum(int i){return data[i];}
        bool isempty(){return currentLength==0;}

};

template <class elemType>
class seqStack{
    private:
        elemType *data;
        int currentLength;
        int maxSize;
    public:
        seqStack(int initSize=10){
            data=new elemType[initSize];
            maxSize=initSize;
            currentLength=0;
        }
        ~seqStack(){delete[]data;}
        friend ostream& operator<<(ostream& os, const seqStack& cp){//重载<<
            int i=cp.currentLength;
            while(i!=0)os<<cp.data[--i]<<' ';//!cp.isempty()?????
            return os;
        }
        void push(const elemType &aa){
            data[currentLength]=aa;
            currentLength++;
        }
        elemType pop(){
            //data[currentLength]=aa;
            currentLength--;
            return data[currentLength];
        }
        bool isempty(){
            return (currentLength==0);
        }
        void clear(){currentLength=0;}
        elemType top(){
            return data[currentLength-1];
        }
};



template <class elemType>
class NODE{
    public:

        elemType data;
        NODE *next;

        NODE(elemType da, NODE *p = NULL){
            this->data=da;this->next=p;
        }
        NODE():next(NULL){}
        ~NODE(){}
};


/*
template <class elemType>
class LinkList{
    private:
        int currentLength;
        NODE <elemType> *HEAD, *TAIL;

    public:
        LinkList(){HEAD=TAIL=NULL;currentLength=0;}
        ~LinkList(){delete HEAD;delete TAIL;}
        friend ostream& operator<<(ostream& os, const LinkList& cp){//重载<<
            NODE <elemType> *tmp=cp.HEAD;
            while(tmp!=NULL)os<<tmp->data<<' ',tmp=tmp->next;
            return os;
        }
        void insert(const elemType &aa, int ii){
            NODE <elemType> *tmp=HEAD;
            NODE <elemType> *tempnode = new NODE <elemType> (aa);
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            tempnode->next=tmp->next;
            tmp->next=tempnode;
            currentLength++;
        }
        elemType del(int ii){
            //data[currentLength]=aa;
            currentLength--;
            elemType tmpm;
            NODE <elemType> *tmp=HEAD;
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            tmpm=tmp->next->data;
            tmp->next=tmp->next->next;
            return tmpm;
        }
        void insert(const elemType &aa){
            int ii=currentLength;
            NODE <elemType> *tmp=HEAD;
            NODE <elemType> *tempnode = new NODE <elemType> (aa);
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            tempnode->next=tmp->next;
            tmp->next=tempnode;
            currentLength++;
        }
        elemType del(){
            int ii=currentLength;
            //data[currentLength]=aa;
            currentLength--;
            NODE <elemType> *tmp=HEAD;
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            elemType tmpm=tmp->next->data;
            tmp->next=tmp->next->next;
            return tmpm;
        }
        bool isempty(){
            return HEAD->next==NULL;
        }
        
};*/


template <class elemType>
class LinkList{
    private:
        int currentLength;
        NODE <elemType> *HEAD;

    public:
        LinkList(){}
        ~LinkList(){
            clear();
            delete HEAD;
        }
            
        void clear(){
            NODE <elemType> *p=HEAD->next, *q;
            HEAD->next=NULL;
            while (p){
                q=p->next;
                delete p;
                p=q;
            }
        }
        
        friend ostream& operator<<(ostream& os, const LinkList& cp){//重载<<
            NODE <elemType> *tmp=cp.HEAD;
            while(tmp!=NULL)os<<tmp->data<<' ',tmp=tmp->next;
            return os;
        }

        int length(){
            int count = 0;
            NODE<elemType> *p = HEAD->next;
            while(p!=NULL){count++;p=p->next;}
            return count;
        }

        void insert(int i, const elemType &x);

        elemType del(int i){
            if(i<0)return 0;
            NODE <elemType> *tmp, *p = HEAD;
            for (int j=0;p&&j<i-1;++j)p=p->next;
            if(!p||!p->next)return 0;
            tmp=p->next;
            p->next=tmp->next;
            elemType ans=tmp->data;
            delete tmp;
            return ans;
        }

        bool isempty(){
            return (HEAD==NULL);
        }
};

template <class elemType>
void LinkList<elemType>::insert(int i, const elemType &x){
    if (i<0) return;
    NODE <elemType> *p = HEAD;
    for (int j=0;p&&j<i-1;++j)p=p->next;
    if(!p)return;
    NODE<elemType> *tmp = new NODE<elemType>;
    tmp->data = x;
    tmp->next = p->next;
    p->next = tmp;  //这句语句导致错误，原因不明.
}


template <class elemType>
class LinkStack{
    private:
        int currentLength;
        NODE <elemType> *Top;

    public:
        LinkStack(){Top=NULL;}
        ~LinkStack(){
            NODE <elemType> *tmp;
            while (Top!=NULL){
                tmp=Top;
                Top=Top->next;
                delete tmp;
            }
        }
        friend ostream& operator<<(ostream& os, const LinkStack& cp){//重载<<
            NODE <elemType> *tmp=cp.Top;
            while(tmp!=NULL)os<<tmp->data<<' ',tmp=tmp->next;
            return os;
        }
        void push(const elemType &aa){
            Top=new NODE<elemType>(aa,Top);
        }
        elemType top()const{if(Top!=NULL)return Top->data;return 0;}
        elemType pop(){
            if(Top==NULL)return 0;
            NODE <elemType> *tmp = Top;
            elemType x = Top->data;
            Top = Top->next;
            delete tmp;
            return x;
        }
        bool isempty(){
            return (Top==NULL);
        }
};

void seqListTEST() {
    cout<<"Now we do seqList TEST. Type in the number of elements: ";
    seqList<int>sl1;
    int n,tmp;
    cin>>n;
    cout<<"Type in elements to insert in the list: ";for (int i=1;i<=n;i++)cin>>tmp,sl1.insert(tmp);
    cout<<"What's in the list?  ";cout<<sl1<<'\n';
    cout<<"What's the number of elements in this list?  ";cout<<sl1.getnum(n-1)<<'\n';
    cout<<"Now deleting elements in this list: ";while(!sl1.isempty())cout<<sl1.del()<<' ';cout<<'\n';
}

void seqStackTEST() {
    cout<<"Now we do seqStack TEST. Type in the number of elements: ";
    seqStack <int> LS1;
    int n,tmp;
    cin>>n;
    cout<<"Type in elements to push in the stack: ";for(int i=1;i<=n;i++)cin>>tmp,LS1.push(tmp);
    cout<<"What's in the stack?  ";cout<<LS1<<'\n';
    cout<<"What's the top element in this stack?  ";cout<<LS1.top()<<'\n';
    cout<<"Now poping elements in this stack: ";while(!LS1.isempty())cout<<LS1.pop()<<' ';cout<<'\n';
}

void LinkListTEST(){
    LinkList<int>sl1;
    int n,tmp;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>tmp,sl1.insert(i-1,tmp);
    cout<<sl1<<'\n';
    int nn=0;
    while(!sl1.isempty())cout<<sl1.del(nn)<<' ',n++;
}

void LinkStackTEST() {
    cout<<"Now we do LinkStack TEST. Type in the number of elements: ";
    LinkStack <int> LS1;
    int n,tmp;
    cin>>n;
    cout<<"Type in elements to push in the stack: ";for(int i=1;i<=n;i++)cin>>tmp,LS1.push(tmp);
    cout<<"What's in the stack?  ";cout<<LS1<<'\n';
    cout<<"What's the top element in this stack?  ";cout<<LS1.top()<<'\n';
    cout<<"Now poping elements in this stack: ";while(!LS1.isempty())cout<<LS1.pop()<<' ';cout<<'\n';
}

int main(){

    seqListTEST();
    
    seqStackTEST();

    //LinkListTEST();
    // Line 220 caused error. The reason is unclear.

    LinkStackTEST();

    cout<<"\nEND OF TESTS.\n\n";
}