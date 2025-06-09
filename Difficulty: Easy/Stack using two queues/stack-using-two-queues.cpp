/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
void QueueStack ::push(int x) {
    // code here
    // Push x first in empty q2
        q2.push(x);

        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // swap the names of two queues
        swap(q1, q2);
    
}

int QueueStack ::pop() {

    // if no elements are there in q1
         if(q1.empty()) return -1;
        else
        {
         int ele=q1.front();
         q1.pop();
         return ele;
    }   
    
}
     
