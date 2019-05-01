
struct node{
                                                                                //Properties
	int element;
	node *next;
};

class List {
                                                                                //properties
public:
	struct node *head;
	struct node *tail;

	List()                                                                      //default constructor
	{
	    head=NULL;
	    tail=NULL;
	}

    bool isEmpty()                                                              //Function to checck if list isEmpty or not
    {
        if(head==NULL)
            return true;
        else
            return false;
    }

	void makeNULL()                                                             //Makes the List NULL
	{
		head=NULL;
		tail=NULL;
	}

    int pop()                                                                   //firstIN LAST out
	{
	    int x;
	    if(head==NULL)
            return -1;

        else if(head->next==NULL)
        {
            x=head->element;
            free(head);
            head=NULL;
            tail=NULL;
        }
        else
        {
            node *temp=new node;
            temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            x=temp->next->element;
            temp->next=NULL;
            free(temp->next);
        }

    return x;
}
    int dequeue()                                                                 //firstIN first out
	{
        int x;
	    if(tail==NULL)
            cout<<" NOT Possible to dequeue further "<<endl;

        else if(head->next==NULL)
        {
            x=head->element;
            free(head);
            head=NULL;
        }

        else
        {
            node *temp=new node;
            x=head->element;
            temp=head->next;
            free(head);
            head=temp;
            //struct node *t;
        }

    return x;
	}

	int peek()                                                                      //check whether list is empty
	{

	    if(head!=NULL)
        {
            return head->element;
        }
        return -1;
	}

	int nextExist()                                                                 //whether next element in list exists
	{
	    if(head->next!=NULL)
            return 1;
        return 0;
	}

                                                                                    //this method adds an element x at last position
	void add(int x)
	{
		node *temp=new node;
		temp->element=x;
		temp->next=NULL;

		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=tail->next;
		}
	}
    int top()
    {
        node *temp=new node;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            return temp->element;
    }
	void print()                                                                //prints the list
	{
	    node *temp=new node;
	    temp=head;
	    while(temp!=NULL)
        {
            cout<<temp->element<<" ";
            temp=temp->next;
        }
	}

	bool isThere(int x)                                                         //checks whether some 'x' is in the list
	{
	    bool flag=0;
	    while(!isEmpty())
        {
            node *temp=new node;
            temp=head;
            if(temp->element==x)
            {
                flag=1;
                break;
            }
        }
        return flag;
    }

    void revList()                                                                 //Reverses the list
    {
        if(head == NULL) return;

        struct node *prev = NULL, *current = NULL, *next = NULL;
        current = head;
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    // now let the head point at the last node (prev)
    head = prev;
    }
};

