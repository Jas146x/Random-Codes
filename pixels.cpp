#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void dispstack(stack<int> s)
{
    stack<int> s1 = s;
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
}

void dispqueue(queue<int> q)
{
    queue<int> q1 = q;
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
}


int largestq(queue<int> q)
{
    queue<int> q1 = q;
    int large;
    while(!q1.empty())
    {
        large = q1.front();
        q1.pop();
        if(large < q1.front())
           large = q1.front();
        return large;
    }
}

int arrangeq(queue<int> q)
{
    queue<int> q1 = q;
    int element;
    while(!q1.empty())
    {
        element = q1.front();
        q1.pop();
        if(element > q1.front())
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    int i; 
    cin>>n;
    int data[n];
    for(int i = 0; i < n; i++)
    {
        cin>>data[i];
    }
    stack<int> s;
    queue<int> q;
    i = 0;
    while(i<n)
    {
        if((s.empty() && q.empty()) || (data[i] >= q.back()))
        {
            q.push(data[i]);
        }
        else if(s.empty() || (data[i] <= s.top()))
        {
            s.push(data[i]);
        }
        else
        {
            while(!s.empty())
            {
                if(s.top() < q.front())
                {
                    q.push(s.top());
                    s.pop();
                }
                else if((s.top() > largestq(q)) && arrangeq(q))
                {
                    q.push(s.top());
                    s.pop();
                }
                else if(s.top() == q.back())
                {
                    q.push(s.top());
                    s.pop();
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
            
            while(q.front() < data[i])
            {
                q.push(q.front());
                q.pop();
            }
            
            s.push(q.front());
            q.pop();
            s.push(data[i]);
            
            while(q.front() > q.back())
            {
                q.push(q.front());
                q.pop();
            }
        }
        if(!q.empty())
        {
           dispqueue(q);cout<<endl; 
        }
        if(!s.empty())
        {
           dispstack(s);cout<<endl;
        }
        i++;
    }
    return 0;
}
