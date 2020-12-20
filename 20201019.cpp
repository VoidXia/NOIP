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
        elemType del(int ii=currentLength){
            //data[currentLength]=aa;
            currentLength--;
            return data[currentLength+1];
        }

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
            while(!isempty())os<<cp.data[--i]<<' ';
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
};



template <class elemType>
class NODE{
    public:

        elemType *data;
        NODE *next;

        NODE(elemType da, NODE *p = NULL){
            this->data=da;this->next=p;
        }
};

template <class elemType>
class LinkList{
    private:
        int currentLength;
        NODE <elemType> *HEAD, *TAIL;

    public:
        LinkList(){HEAD=TAIL=NULL;}
        ~LinkList(){delete HEAD;delete TAIL;}
        friend ostream& operator<<(ostream& os, const LinkList& cp){//重载<<
            NODE <elemType> *tmp=cp.HEAD;
            while(tmp!=NULL)os<<tmp->data<<' ',tmp=tmp->next;
            return os;
        }
        void insert(const elemType &aa, int ii=currentLength){
            NODE <elemType> *tmp=HEAD;
            NODE <elemType> *tempnode = new NODE <elemType> (aa);
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            tempnode->next=tmp->next;
            tmp->next=tempnode;
            currentLength++;
        }
        void del(int ii=currentLength){
            //data[currentLength]=aa;
            currentLength--;
            NODE <elemType> *tmp=HEAD;
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            tmp->next=tmp->next->next;
        }
};

template <class elemType>
class LinkStack{
    private:
        int currentLength;
        NODE <elemType> *HEAD, *TAIL;

    public:
        LinkStack(){HEAD=TAIL=NULL;}
        ~LinkStack(){delete HEAD;delete TAIL;}
        friend ostream& operator<<(ostream& os, const LinkStack& cp){//重载<<
            NODE <elemType> *tmp=cp.HEAD;
            while(tmp!=NULL)os<<tmp->data<<' ',tmp=tmp->next;
            return os;
        }
        void push(const elemType &aa, int ii=currentLength){
            NODE <elemType> *tmp=HEAD;
            NODE <elemType> *tempnode = new NODE <elemType> (aa);
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            tempnode->next=tmp->next;
            tmp->next=tempnode;
            currentLength++;
        }
        elemType pop(int ii=currentLength){
            //data[currentLength]=aa;
            currentLength--;
            NODE <elemType> *tmp=HEAD;
            while(tmp!=NULL&&ii)ii-=1,tmp=tmp->next;
            tmp->next=tmp->next->next;
        }
        bool isempty(){
            return (currentLength==0);
        }
        void clear(){currentLength=0;}
};