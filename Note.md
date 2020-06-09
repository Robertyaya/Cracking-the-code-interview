# Most important concept

## Data Structure
* Linked list
* Tree, Graph, Trie
* Stack, Queue
* Heap
* Array
* Hash

## Algorithm
* BFS
* DFS
* Binary Search
* Merge Sort
* Quick Sort

## Concept
* Bitwise operator
* Memory (stack and heap)
* Recursion
* DP
* Big O time and space complexity


# Chapter 1: Array and String

## Concept

* Hash Table
* ArrayList (vector)
* String

### 1-1 Find Unique
Method 1: Time: O($n^2$), Space: O(1)
````c++
bool isUniqueChar(string str)
{
    for i (0 to str.size())
    {
        for j (0 to str.size())
        {
            if(str[i] == str[j])
                return false;
        }
    }
    return true;
}
````
Method 2: Time: O($n$), Space: O(1)
````c++
bool isUniqueChar(string str)
{
    // ASCII total is size 128
    if(str.size > 128)
        return false;
    
	// Same as build the hash table	
    vector<bool> char_set(128)
    for i (0 to str.size())
    {
        // Get ASCII code
        val <- (int)str[i]
            
        if(char_set[val])
            return false;
        
        char_set[val] = true;
    }
    return true;
}
````
Method 3: Time: O($n$), Space: O(1)
````c++
bool isUniqueChar(string str)
{
    // Use bit vector to reduce the space
    // A bool occupied 8 bits
    bitset<128> bits(0)
    for i (0 to str.size())
    {
        val <- (int)str[i]
            
        if(bitset[val])
            return false
            
        char_set[val] = true;
    }
    return true
}
````
### 1-2 Check Permutation
Method1: Time: O($nlogn$), Space: O(1)
````c++
// Sorting and compare whether the two string are the same
bool arePermutation(str1, str2)
{
    n1 <- str1.size
    n2 <- str2.size
        
    if (n1 != n2)
        return false
    
    // O(nlogn)    
    sort(str1)
    sort(str2)
    
    // O(n)
    for i (0 to n1)
    {
        if(str1[i] != str2[i])
            return false
    }
    return true
}
````
Method2: Time: O($n$), Space: O(1)
````c++
bool arePermutation(str1, str2)
{	
    if(str1.size != str2.size)
        return false
        
    // ASCII code size
	int array[128] <- {0}
    
    // string 1
    for i (0 to str1.size)
    {
        val <- (int)str1[i]
        array[val]++
    }
    
    // string 2
    for i (0 to str2.size)
    {
        val <- (int)str2[i]
        array[val]--
            
        if(array[val] < 0)
            return false
    }
    return true
}
````
### 1-3 Check Space
Method: Time: O(length), Space: O(1)
````c++
void replaceSpace(str, length)
{
    string output
    for i (0 to length)
    {
        if(str[i]==' ')
            output += "%20"
        else
            output += str[i]
    }
}
````

### 1-4 Palindrome Permutation
Method 1: Time: O(str.size), Space: O(1)
````c++
bool isPermutationOfPalindrome(str)
{
    // Calculate the frequency of every char
    int count[128]
    for i (0 to str.size())
    {
        value <- (int)str[i]
        count[value]++
    }
    
    cont <- 0
    for i (0 to str.size())
    {
		value <- (int)str[i]
        
        // if count[value] % 2 == 0 represent this char is couple
        if (count[value] % 2 == 1)
            cont++
    }
    // cont == 0 represent every char is couple, therefore, this string is palidrome
    // cont == 1 represent there are one char is not couple, we need to check the size of string whether is odd
    return cont == 0 || (cont == 1 && str.size() % 2 ==1)
}
````
Method 2: Time: O(str.size), Space: O(1)
````c++
bool isPermutationOfPalindrome(str)
{
    // Calculate the odd during the process when calculating the char frequency
    // Only one for loop
    int count[128]
    count_odd <- 0
    for i (0 to str.size())
    {
        value <- (int)str[i]
        count[value]++
        if(count[value] % 2 == 1)
            count_odd++
        else
            count_odd--
    }
    return count_odd <= 1
}
````
### 1-5 One Away
Method: Time: O(str.size), Space: O(1)
````c++
bool OneAway(str1, str2)
{
    str_long = LongSize(str1, str2)
    str_short = ShortSize(str1, str2)
    
    int table[128]
    int edit_count = 0
    for i (0 to str_short.size())
    {
        value <- (int)str_short[i]
        table[value]++
    }
    for i (0 to str_long.size())
    {
        value <- (int)str_short[i]
        table[value]--
        
        if (table[value] < 0)
            edit_count++
        if(edit_count > 1)
        	return false
    }
    return true
}
````
### 1-6 Compress String
Method: Time: O(str.size), Space: O(1)
````c++
std::string CompressString(str)
{
    // Element initialize
    count <- 1 // Count the char number
    answer <- ""
    previous_char <- str[0]
    
	for i (1 to str.size())
    {
        if(str[i] != previous_char || i == last_index)
        {
            // Handle the last element equal to previous char
            if(str[i] == previous_char
               count++;
            answer = answer + previous_char + (string)count
            
            // Handle the last element not equal to previous char
            if(i = last_index && str[i] != previous_char)
               answer = answer + str[i] + "1"
        }
        else // current char equal to previous char, keep count the value
            count++
    }
	return answer.size < str.size ? answer.size : str.size
}
````
### 1-7 Rotation Matrix
Method: Time: O($n^2$), Space: O(1)
````c++
void Rotate(Matrix, N)
{
    // Top -> temp
    // Left -> Top
	// Botton -> Left
    // Right -> Botton
    // temp -> Right
    for layer (0 to N/2)
    {
        first_index <- layer
        last_index <- N-layer-1
        for i (first_index to last_index)
        {
			// Save the top value
            temp <- Matrix[top line]
                
            Matrix[top line] <- Matrix[left line]
                
            Matrix[left line] <- Matrix[bottom line]
                
            Matrix[bottom line] <- Matrix[right line]
                
            Matrix[right line] = temp
        }
    }
}
````
### 1-8 Zero Matrix
Method: Time: O($N*M$), Space: O(1)
````c++
void Zero_Matrix(Matrix, int M, int N)
{
    // Record the row and col when get zero
    vector
    for i (0 to M)
    {
        for j (0 to N)
        {
			if(Matrix[i][j] == 0)
            {
                vector.push_back(i,j)
                break
            }
        }
    }
    
    for i (0 to vector.size)
    {
        int row = vector[i].first
        int col = vector[i].second
        
        // Fill the zero in row
        for y (0 to N)
        	matrix[row][y] = 0
        
        // File the zero in col
       for z (0 to M)
    		matrix[z][col] = 0
    }
}
````
### 1-9 Rotate Matrix
Method: Time: O(s1.size * s2.size), Space: O(1)
````c++
// We have the function isSubString(str1, str2) can know whether the str2 is the substring of the str1
bool isRotation(s1, s2)
{
    // check its length
    if(s1.size != s2.size)
        return false
    // If s1 and s2 is rotation, we can derive s1 = xy, then s2 = yx.
	// Therefore s1+s1 = xyxy -> the s2 must be the substring of the s1s1
    s1s1 = s1 + s1
    return isSubString(s1s1, s2) // O(s1.size * s2.size) 
}
````

# Chapter 2: Linked List

Basic struct:
````c++
struct Node
{
	int data
    Node* next
}

class LinkedList
{
public:
    void PrintList() // Ouput the linked list
    void Push_Front(int data) // Put the data at front
    void Push_Back(int data) // Put the data at back
    void Delete(int data) // Delete the target data
    void Clear() // Clear the linked list
    void Reverse() // Reverse the linked list
        
private:
    Node* root // Point to the first node in the linked list
    Node* last // Point to the last node in the linked list
    int size // Record the size of the linked list
}
````
PrintList: O($n$)
````c++
void PrintList()
{
    Node* current
    
    // No node in linked list
    if(root == nullptr)
        return 
    while(current != nullptr)
    {
    	printf(current->data)
        current = current->next // move to the next node
    }
}
````
Push_Front: O(1)
````c++
void Push_Front(int data)
{
    // Allocate new node
    Node* temp = new Node(data)
    
    // If the linked list is empty
    if(root == nullptr)
    {
		root = temp
        last = temp
    }
    else
    {
		temp->next = root
        root = temp
    }
  	size++
}
````
Push_Back: O(1) (Due to we record the last element)
````c++
void Push_Back(int data)
{
    // Allocate new node
    Node* temp = new Node(data)
        
    // If the linked list is empty
    if(root == nullptr)
    {
        root = temp
        last = temp
    }
    else
    {
        last->next = temp
        last = temp
    }
    size++
}
````
Delete: O($n$)
````c++
void Delete(int data)
{
    Node* current = root
    Node* previous = nullptr
    
    // The target the data is the first element
    if(root->data == data)
    {
        root = root->next
        delete current
        current = nullptr
        size--
        return
    }
  
    while(current->next != nullptr)
    {
        // Update the temp node
        previous = current
        current = current->next

        // Find the target data
        if(current->data == data)
        {
            previous->next = current->next
            delete current
            current = nullptr
            size--
            return
        }
    }
}
````
Clear: O($n$)
````c++
void Clear()
{
    Node* current
    while(root != nullptr)
    {
        current = root
        root = root->next
        delete current
    }
    size = 0
}
````
Reverse: O($n$)
````c++
void Reverse()
{
    if(size == 0 || root->next == nullptr)
    	return
    
    Node* previous = nullptr
    Node* current = root
    Node* preceding = root->next
    
    last = root
    while(current != nullptr)
    {
        // Reverse the linked list
        current->next = previous
        
        // Update the temp node
        previous = current
        current = preceding
        if(current == nullptr)
        	break
        preceding = preceding->next
    }
    root = previous
}
````
### 2-1 Remove Duplicate
Method 1: Time: O($n^2$), Space: O(1)

Don't need to extra space to record data
````c++
void RemoveDul()
{
    if(root == nullptr || root->next == nullptr)
        return
        
    Node *current, *runner
    while(current != nullptr)
    {
        runner = current
        while(runner->next != nullptr)
        {
            if(current->data == runner->next->data)
            {
                Node* temp = runner->next
                runner->next = runner->next->next
                delete temp
            }
            else
            {
                runner = runner->next
            }
        }
        current = current->next
    }
}
````
Method 2: Time: O($n$), Space: O(n)

Need extra space to build the hash map
````c++
void RemoveDul()
{
    if(root == nullptr || root->next == nullptr)
    	return
    
	// Hash table
    unorder_map<int, int> map
        
    Node* current = root->next
    Node* previous = root   
    map[previous->data] = 1
    while(current != nullptr)
    {
        // Represent this data is duplicate, need to remove
        if(map.find(current->data) != map.end())
        {
            // Use temp to point to the node need to remove
            Node* temp = current
            previous->next = current->next
            current = current->next
            delete temp
        }
        else
        {
             // Update the current and previous node
        	current = current->next
        	previous = previous->next
        }
    }
}
````
### 2-2 Kth to Last -> Return the k to last node
`k -> the k value for finding kth element from last of the list `

Method 1: Time: O($n$), Space: O($n$)

Use recursive method
````c++
Node* kthToLast(Node* head, int& i, int k)
{
    if(head == nullptr)
        return nullptr
    
    // Use recursive arrive the last node first
    Node* node = kthToLast(head->next, i, k)
        
    i = i + 1
    if(i==k)
        return head
    return node
}

Node* kthToLastRecursive(int k)
{
    if (k==0)
        return nullptr
    Node* head = root
    i = 0 //Use i to record the count
    return kthToLast(head, i, k)  
}
````
Method 2: Time: O($n$), Space: O(1)

Use iterative method whcih is more efficient than recursive method
````c++
Node* kthToLastIterate(int k)
{
    if (k==0)
    	return nullptr
        
    Node* first = root
    Node* second = root
    
    // We move the first k step, therefore, the distance between pointer first and the last node = (size - k)
    for i (0 to k-1)
    {
        first = first->next
        // Represent the k is bigger than the size of linked list
        if(first == nullptr) 
            return nullptr
    }
    
    // In this while loop, we will move pointer second (size-k) step, therefore the distance between pointer second and the last node is size - (size - k) = k
    while(first != nullptr)
    {
        second = second->next
        first = first->next
    }
    return second
}
````
### 2-3 Delete Middle Node
The input is the node which need to be removed, we can't use the root of linked list

Method: Time: O(1), Space: O(1)
````c++
void DeleteNode(Node* remove)
{
    // Represent the remove node is the last node in the linked list, therefore we can't remove it 
    if(remove->next == nullptr)
        return 
        
    Node* next_node = remove->next
    // Move the next node's data and next pointer to the current node, then delete the next node
    remove->next = next_node->next
    remove->data = next_node->data 
    delete next_node
}
````
### 2-4 Partition
Method: Time: O(n), Space: O(n) // Need to create new linkedlist
````c++
Node* Partition(int pivot)
{
    Node* runner // Use to transverse every node in linked list
    Node* pivot_node = root // Point to the pivot node 
    count <- pivot // Use to count whether we arrive the pivot node
    while(count!=1)
    {
        pivot_node = pivot_node -> next
        count--
    }
    
    Node* left_strart = nullptr // Point to the left start node (no move)
    Node* left_end = nullptr // Point to the left end node (will move)
    Node* right_start = new Node(pivot_node->data) // Point to the pivot node (no move)
    Node* right_end = right_start // Point to the right end node (will move)
    
    // Transverse every node in linked list
    while(runner!=nullptr)
    {
        // When meet the pivot node, skip it to the next node
        if(runner == pivot_node)
        {
            runner = runner->next
            continue
        }
        
        if(runner->data < pivot)
        {
            Node* temp = new Node(runner->data)
            
            // Initial left side node
            if(left_start == nullptr || left_end == nullptr)
            {
                left_start = temp
                left_end = temp
            }
            
            left_end->next = temp
            left_end = left_end->next
        }
        else
        {
            Node *temp = new Node(runner->data);
            right_end->next = temp;
            right_end = right_end->next;
        }
        
        runner = runner->next
    }
    // Connect left side and right side
	left_end->next = right_start
    right_end->next = nullptr
    return left_start
}
````
### 2-5 Sum of linkedlist
Method: Time: O(n), Space: O(n) // Need to create new linkedlist
````c++
Node* SumOfList(Node* a, Node* b)
{
    Node* sum = nullptr // New linkedlist, record the sum of a+b
    Node* sum_runner = nullptr // To transverse the new linked list
    Node* a_runner = a // To transverse the a linkedlist
    Node* b_runner = b // To transverse the b linkedlist
        
    int place = 0 // Revord the sum whether the last node bigger than ten, if the last node bigger than ten, we need to plus 1 in current node
	while(a_runner != nullptr || b_runner != nullptr)
    {
        if(a_runner == nullptr) // Represent a linkedlist don't have any node
        {
            // Initialize the sum linkedlis 
            if(sum_runner == nullptr)
            {
                sum = new Node(b_runner->data)
                sum_runner = sum
            }
            else
            {
                Node* temp = new Node(b_runner->data + place)
                sum_runner->next = temp;
        		sum_runner = sum_runner->next;
            	// Initial the place
        		if (place != 0)
         			place = 0;
            }  
        }
        else if (b_runner == nullptr) // Represent b linkedlist don't have any node
        {
        	if (sum_runner == nullptr)
         	{
        		sum = new Node(a_runner->data);
            	sum_runner = sum;
          	}
          	else
          	{
            	Node *temp = new Node(a_runner->data + place);
            	sum_runner->next = temp;
            	sum_runner = sum_runner->next;
                // Initial the place
            	if (place != 0)
              		place = 0;
         }
        else // Represent a and b both have node
    	{
            // Need to check total whether bigger than 10, if bigger than 10, we need to place 1 in next sum of node
      		int total = a_runner->data + b_runner->data + place;
      		if (place != 0)
        		place = 0;
      		if (total >= 10)
      		{
        		place++;
        		total -= 10;
      		}

      		if (sum_runner == nullptr)
      		{
        		sum = new Node(total);
        		sum_runner = sum;
      		}
      		else
      		{
        		Node *temp = new Node(total);
        		sum_runner->next = temp;
        		sum_runner = sum_runner->next;
      		}
    	}
        
        // Update the a_runner and b_runner, we need to transverse a,b linkedlist
        if (a_runner == nullptr)
      		b_runner = b_runner->next;
    	else if (b_runner == nullptr)
     		a_runner = a_runner->next;
    	else
    	{
    		a_runner = a_runner->next;
      		b_runner = b_runner->next;
    	}
    }
    return sum
    
}
````
### 2-5 Sum of linkedlist (follow up)
Method: Time: O($n$)
Need to use recursive to reach the last node first
````c++
void SumOfListRecursive(Node* sum, Node* sum_last, int carry, Node* a, Node* b)
{
    // Arrive the last node in linked list
    if(a==nullptr || b==nullptr)
        return 
    SumOfListRecursive(sum_linked_list, sum_last, carry, a, b)
    
    // Add two linked list's node and previous carry
    int sum_num = a->data + b->data + carry
    if(sum_num > 9)
    {
        carry = 1
        sum_num-=10
    }
    else
    {
        // update next position's carry
        carry = 0
    }
    
    // Initialize
    if(sum == nullptr)
    {
        sum = new Node(sum_num)
        sum_last = sum
    }
    else
    {
        Node* temp = new Node(sum_num)
        sum_last->next = temp
        sum_last = temp
    }
}
Node* SumOfList_FollowUp(Node* a, Node* b)
{
    // The sum of a and b
    Node* sum_linked_list = nullptr
    Node* sum_last = nullptr
    // Calculate the length of linked list a and b
	len1 <- length(a)
    len2 <- length(b)
    
    // Fill the zero to shoter linked list
	if(len1 > len2)
    	padList(b, len1-len2)
    else
        padList(a, len2-len1)
    
    carry <- 0
    // O(2N)
    SumOfListRecursive(sum_linked_list, sum_last, carry, a, b)
    // O(N)
    Reverse(sum_linked_list)
    return sum_linked_list
}
````
### 2-6 Palindrome
Reverse the linked list and compare the half of linked list

Method 1: Time: O($n$), Space: O($n$) (need to create a reverse linked list)
````c++
bool Compare(Node* root, Node* reverse_linkedlist, int size)
{
    if(size % 2 == 0)
    {
        for i (0 to size/2)
        {
            if(root->data != reverse_linkedlist->data)
                return false
            
            // Update to next node
            a = a->next
            b = b->next
        }
    }
    if(size % 2 != 0)
    {
        for i (0 to (size/2)+1)
        {
            if(root->data != reverse_linkedlist->data)
                return false

            // Update to next node
            a = a->next
            b = b->next
        }
    }
    return true
}
bool Palindrome(Node* root)
{
    // Create a reverse_linkedlist
    Node* reverse_linkedlist = Reverse(root)
    
    // Compare the half of linked list to check whether the linked list is the palindrome
    return Compare(root, reverse_linkedlist, size)
}
````
Method 2: Time: O($n$), Space: O($n$) (need to use stack to store the value)

This situation is the size of linked list is unknown. Therefore, use two nodes "slow" and "fast" to transverse the linked list, when "fast" node arrive the last node, the "slow" node arrive the middle of the linked list
````c++
bool Palindrome(Node* node)
{
    Node* slow = node
    Node* fast = node
    stack<int> temp_stack
    while(fast != nullptr && fast->next != nullptr)
    {
        temp_stack.push(slow->data)

        // Update the slow node
        slow = slow->next
        // The linked list is even and arrive the last node
        if(fast->next->next == nullptr) 
        {
            fast = fast->next
            break
        }
        
        // Update the fast node
        fast = fast->next->next
        // The linked list is odd, and arrive the last node, we don't need to store the middle node so we pop up
        if(fast->next == nullptr)
            temp_stack.pop()
    }
    
    // "slow" start from middle node
    while(slow != nullptr)
    {
        slow = slow->next
        if(slow->data != temp_stack.top())
            return false
        else
            temp_stack.pop()
    }
    return true
}
````
Method 3: Time: O($n$), Space: O($n$) 

Call the recursive function to compare the (1,n), (2,n-1)...
````c++
bool Palindrome_recursive(Node*& left, Node* right)
{
    // The base case of right node
    if(right == nullptr)
        return true
    // Move the right node to the next, until it arrive the last node
    bool flag = Palindrome_recursive(left, right->next)
    if(!flag)
        return false
    
    // Not equal, represent this linked list is not the Palindrome, we directly return false
    if(left->data != right->data)
        return false
    
    // Move the left node to the next
    left = left->next
    return true
}

bool Palindrome()
{
    return Palindrome_recursive(root, root)
}
````
### 2-7 Interaction
Method 1: Time: O($n$), Space: O($n$)

Use the hash table to store the first linked list first, and then check the second linked list whether have same memory address
````c++
Node* Interaction(Node* a, Node* b)
{
    // Key: memory address of node, value is node's data
    unorder_map<Node*, int> hash_table
    Node* a_runner = a
    Node* b_runner = b
    
    // Use a linked list to build the hash table
    while(a_runner!=nullptr)
    {
        hash_table[a_runner] = a_runner->data
        a_runner = a_runner->next
    }

    // Transverse the b linked list to check every node whether store in the hash table
    while(b_runner!=nullptr)
    {
        // Represent can find the correspond data, therefore have the interaction
        if(hash_table.find(b_runner)!=hash_table.end())
            return b_runner
        b_runner = b_runner->next
    }
    // Can't find the interaction
    return nullptr
}
````
### 2-8 Loop detection
Method: Time: O($n$), Space: O(1)
````c++
Node *LinkedList::LoopDetection()
{
    // Define two ptr, fast and slow
    Node* fast = root
    Node* slow = root
    
    while(fast!=nullptr && fast->next!=nullptr && slow!=nullptr)
    {
        // The fast ptr is faster than slow ptr twice
        fast = fast->next->next
        slow = slow->next

        // Fast ptr and slow ptr meet, represent this linked list has a loop
        // 假設root距離進入loop起始點k個node, 則fast and slow一定會在loop中離起始點k個node的地方相遇
        // Prove: 當slow在loop的起始點時(已走了k個node), fast走了2k個node, 代表已進入loop中k個node. 
        // 假設一個loop共x個node, fast需要x-k個node才能追上slow, 代表slow會在loop中走了x-k個node後被追上
        if(slow == fast)
        {
            Node* meet_point = root
            while(start != fast)
            {
                meet_point = meet_point->next
                fast = fast->next
            }
            return meet_point
        }
    }

    // Represent no loop in the linkedlist, therefore the slow ptr and fast ptr will not meet
    return nullptr
}
````
# Chapter 3: Stack and Queue
## Implement Stack in linked list
````c++
struct Stack_Node
{
    int data
    Stack_Node* next
}
class Stack
{
    Stack_Node* root

    // Push the data into the stack
    Push()

    // Pop up the data in the stack
    Pop()

    // Get the data value in the stack
    Peek()

    // Check the stack whether is empty
    isEmpty()
}

Push(data)
{
    if(root == nullptr)
        root = new Stack_Node(data)
    else
        Stack_Node* temp = new Stack_Node(data)
        temp->next = root
        root = temp
}

int Pop()
{
    if(root == nullptr)
        return -1
    else
        Stack_Node* temp = root
        data = temp->data // Get the data from the top of stack
        root = root->next // Move the root to next node
        delete temp // Release the memory avoid memory leak
        return data        
}

int Peek()
{
    if(root == nullptr)
        return -1
    else
        return root->data
}

bool isEmpty()
{
    if(root == nullptr)
        return true
    else
        return false
}
````
## Implement Queue in linked list
````c++
add(data)
{
    if(root == nullptr)
    {
        root = new Queue_Node(data)
        last = root
    }
    else
    {
        Queue_Node* temp = new Queue_Node(data)
        last->next = temp
        last = temp
    }
}

Remove()
{
    if(root != nullptr)
    {
        Queue_Node* temp = root
        root = root->next
        delete temp
    }
}
````
### 3-1 Three in one
Method: Push( ), Pop( ), Top( ), Time: O(1)
````c++
class FixedMultiStack
{
public:
    FixedMultiStack(stack_capacity)

    // O(1), Push an element onto stack stackNum, where stackNum is from 0~2
    Push(stacknum, value)

     // O(1), Pop the top element from stack stackNum, where stackNum is from 0~2
    Pop(stackNum);

    // O(1), Return the top element on stack stackNum, where stackNum is from 0~2
    Top(stackNum);

private:
    // @brief Get the top of index in the stack
    // @Input choose which stack
    int IndexOfTop(stackNum)

    // @brief Check the stack is empty or not
    // @Input choose which stack
    bool IsEmpty(stackNum)

    // @brief Check the stack is full or not
    // @Input choose which stack
    bool IsFull(stackNum)

private:
    // @brief Three stack put in one arry
    int numofStack = 3

    // @brief The capacity in one stack
    int stackCapacity

    // @brief Array is used to save stack
    int *stackArray

    // @brief Save the capacity have already use in the stack
    int *stackCapacityUsed
}

// Constructor
FixedMultiStack::FixedMultiStack(int stackCapacity)
{
    this->stackCapacity = stackCapacity

    // The default value will set to zero
    stackArray = new int[stackCapacity * numofStack]
    stackCapacityUsed = new int[numofStack]
}

int IndexOfTop(stackNum)
{
    startIndex <- stackCapacity * stackNum
    stack_capacity <- stackCapacityUsed[stackNum]
    return startIndex + stack_capacity -1
}

bool isEmpty(stackNum)
{
    return stackCapacityUsed[stackNum] == 0
}

bool isFull(stackNum)
{
    return stackCapacityUsed[stackNum] == stackCapacity
}

void Push(stackNum, value)
{
    if(isFull(stackNum))
        printf("This stack is full")
    else
        stackCapacityUsed[stackNum]++
        stackArray[IndexOfTop(stackNum)] = value
}

void Pop(stackNum)
{
    if(isEmpty(stackNum))
        printf("This stack is empty")
    else
        stackArray[IndexOfTop(stackNum)] = 0
        stackCapacityUsed[stackNum]--
}

int Top(stackNum)
{
    if(isEmpty(stackNum))
        printf("This stack is empty")
    else
        return stackArray[IndexOfTop(stackNum)]
}
````
### 3-2 Stack Min 
Get the minimize value in the stack. Based on last question. We use the another stack (to handle the pop() might pop up the original GetMinimum value, therefore we need to use stack) to save the GetMinimum value
Method: Time: GetMinimum( ) O(1), Space: O(1)
````c++ 
// Based on 3-1 
class FixedMultiStack
{
public:
    Push()
    Pop()
    Top()
    ...
    GetMinimum(stackNum)
private:
    // @brief Use stack to save the minimum value in the stack
    stack<int>* MinValue_array
}

void Push(stackNum, value)
{
    if(isFull(stackNum))
        printf("This stack is full")
    else
        stackCapacityUsed[stackNum]++
        stackArray[IndexOfTop(stackNum)] = value
    
    // Push the minimun value into stack
    // when the minimum stack is empty, directly push in
    if(stack<int>[stackNum].empty)
       MinValue_array[stackNum].push(value)
    else // If not empty, we need to compare with the top value
    {
        if(value <= MinValue_array[stackNum].top())
            MinValue_array[stackNum].push(value)
    }    
}

void Pop(stackNum)
{
    if(isEmpty(stackNum))
        printf("This stack is empty")
    else
        top_value <- stackArray[IndexOfTop(stackNum)]
        stackArray[IndexOfTop(stackNum)] = 0
        stackCapacityUsed[stackNum]--
    
    // Handle when the minimum value be pop up
    if(top_value == MinValue_array[stackNum].top())
        MinValue_array[stackNum].pop()
}

int GetMinimum(stackNum)
{
    return MinValue_array[stackNum].top()
}
````
### 3-3 Stack of Plates
````c++
class StateofStack
{
    StateofStack(StackSize)
    
    // Push the data into stack, exceed the size of stack need to create new one
    Push(data) // O(1)

    Pop() // O(1)

    // Record the stack of size when initial set
    int StackSize

    // Use vector to store the stack, because we need to create new stack dynamically
    vector<stack<int>> stack_vec
}

Push(data)
{
    stack_index <- stack_vec.size()
    
    // Initialize, no any value in the stack
    if(stack_index == 0)
    {
        stack<int> temp_stack
        temp_stack.push(data)
        stack_vec.push_back(temp_stack)
        return
    }

    // Represent this stack is full, we need to create new one
    if(stack_vec[stack_index-1].size() == stack_size)
    {
        stack<int> temp_stack
        temp_stack.push(data)
        stack_vec.push_back(temp_stack)
    }
    else // This stack is not full, we directly push in
        stack_vec[stack_index-1].push(data)
}

void Pop()
{
    stack_index <- stack_vec.size()

    // Boundary case
    if(stack_index == 0)
        printf("The set of stack is empty")
        return
    
    stack[stack_index-1].pop()

    // Need to check if this stack is empty, we need to pop_back from the vector
    if(stack_vec[stack_index-1] == 0)
        stack_vec.pop_back()

}
````
`Follow up: Need to pop the data based on the input index to choose the stack`
````c++
class StateofStack
{
    StateofStack(StackSize)

    Push(data) // O(1)

    Pop() // O(1)

    // Because we need to move the data
    PopAt(int index) // O(n)

    int StackSize

    vector<stack<int>> stack_vec
}

PopAt(int index)
{
    stack_index <- stack_vec.size()

    // Boundary case
    if(index > stack_index-1)
        printf("This stack is empty")
        return
    
    stack_vec[index].pop()

    // Represent the target index is not the last stack, therefore we need to move all of the data behind this target stack to fill the hole
    if(index != stack_index-1)
        shiftLeftTo(index)
}

shiftLeftTo(index)
{
    stack_index <- stack_vec.size()

    // Use stack to store the temp data
    stack<int> temp_stack
    
    // Put all data behind the target index stack into stack first, then move to left
    // However, we need to keep the priority, we put the data to the stack from the "last" stack to "index+1" stack
    for(i == stack_index-1;i >= index+1 ; i--)
    {
        stack_size <- stack_vec[i].size()
        for j (0 to stack_size)
        {
            temp_data <- stack_vec[i].top()
            temp_stack.push(temp_data)
            stack_vec[i].pop()
        }
        stack_vec.pop_back()
    }

    // We have already save the data in the stack

    // Represent how many data in the stack, we need to push it into the original stack
    temp_stack_size <- temp_stack.size()
    for i (0 to temp_stack_size)
    {
        temp_data <- stack_temp.top()
        this->Push(temp_data)
        stack_temp.pop()
    }
    

}

Push(data)
{
    stack_index <- stack_vec.size()
    
    // Initialize, no any value in the stack
    if(stack_index == 0)
    {
        stack<int> temp_stack
        temp_stack.push(data)
        stack_vec.push_back(temp_stack)
        return
    }

    // Represent this stack is full, we need to create new one
    if(stack_vec[stack_index-1].size() == stack_size)
    {
        stack<int> temp_stack
        temp_stack.push(data)
        stack_vec.push_back(temp_stack)
    }
    else // This stack is not full, we directly push in
        stack_vec[stack_index-1].push(data)
}

void Pop()
{
    stack_index <- stack_vec.size()

    // Boundary case
    if(stack_index == 0)
        printf("The set of stack is empty")
        return
    
    stack[stack_index-1].pop()

    // Need to check if this stack is empty, we need to pop_back from the vector
    if(stack_vec[stack_index-1] == 0)
        stack_vec.pop_back()

}
````
### 3-4 Stacks and Queues
Use two stack to implement the operation of queue
````c++
class MyQueue
{
    // Put data into queue O(1)
    Push(data)

    // Pop data from queue O(N)
    Pop()

    // Get the top front data from queue O(N)
    int front()

private:
    stack<int> stack_1
    stack<int> stack_2
}

Push(data)
{
    stack_1.push(data)
}

Pop()
{
    if(stack1.empty())
        return
    
    // Use the stack2 to reverse the original data
    while(!stack1.empty())
    {
        temp_data <- stack1.top()
        stack2.push(temp_data)
        stack1.pop()
    }
    
    // pop up the front data
    stack2.pop()

    // Put the reverse data to original stack
    while(!stack2.empty())
    {
        temp_data <- stack2.top()
        stack1.push(temp_data)
        stack2.pop()
    }
}

int front()
{
    if(stack1.empty())
        return -1
    
     // Use the stack2 to reverse the original data
    while(!stack1.empty())
    {
        temp_data <- stack1.top()
        stack2.push(temp_data)
        stack1.pop()
    }

    // Record the front data
    int front_data = stack2.top()

    // Put the reverse data to the original stack
    while(!stack2.empty())
    {
        temp_data <- stack2.top()
        stack1.push(temp_data)
        stack2.pop()
    }
}
````
### 3-5 Sorted Stack
````c++
class SortedStack
{
    // Push the data into sorted stack
    Push(data) {sort(data)}
    
    // Pop up the data from sorted stack
    Pop() {sortedstack.pop()}

    // Get the value from sorted stack
    Peek() {return sortedstack.top()}

    // Check the sorted stack whether is empty
    isEmpty() {return sortedstack.empty()}

private:
    sort(int data)
    std::stack<int> sortedstack
}

// Time: O(N), Space: O(N)
sort(int data)
{
    stack<int> temp_stack
    while(!temp_stack.empty() && temp_stack.top() < data)
    {
        temp_stack.push(sortedstack.top())
        sortedstack.pop()
    }
    
    sortedstack.push(data)

    while(!temp_stack.empty())
    {
        sortedstack.push(temp_stack.top())
        temp_stack.pop()
    }
}
````
### 3-6 Animal Shilter
````c++
enum AnimalType
{
    Cat, Dog
};

struct Animal
{
    std::string AnimalName
    AnimalType type
}

class AnimalShilter
{
    // Add animal to shilter
    enqueue(Animal animal)

    // Pop up the arbitrary animal from shilter
    Animal dequeueAny()

    // Pop up the dog from shilter
    Animal dequeDog()

    // Pop up the cat from shilter
    Animal dequeCat()

private:
    std::queue<Animal> cat_queue
    std::queue<Animal> dog_queue
}

enqueue(Animal animal)
{
    // Insert the different queue base on the animal type
    if(animal.type == AnimalType::Cat)
    {
        cat_queue.push(animal)

    }
    else if (animal.type == AnimalType::Dog)
    {
        dog_queue.push(animal)
    }
    else
        printf("The type is neither cat nor dog")
}

Animal dequeueAny()
{
    // The default pop up value is from dog
    if(!dog_queue.empty())
    {
        temp_data <- dog_queue.front()
        dog_queue.pop()
        return temp_data
    }
    else if (!cat_queue.empty())
    {
        temp_data <- cat_queue.front()
        cat_queue.pop()
        return temp_data
    }
    else
        printf("This shilter is empty")
}

Animal dequeCat()
{
    if(!cat_queue.empty())
    {
        temp_data<- cat_queue.front()
        cat_queue.pop()
        return temp_data
    }
    else
        printf("No cat in this shilter")
}

Animal dequeDog()
{
    if(!dog_queue.empty())
    {
        temp_data<- dog_queue.front()
        cdo_queue.pop()
        return temp_data
    }
    else
        printf("No dog in this shilter")
}
````
# Chapter 4: Tree and Graph
## In-order traversal
Transverse the tree node from small to big
````c++
void Inordertraversal(TreeNode node)
{
    if(node != null)
    {
        Inordertraversal(node.left)
        printf(node.data)
        Inordertraversal(node.right)
    }
}
````
## Pre-order traversal
````c++
void PreorderTraversal(TreeNode node)
{
    if(node != null)
    {
        printf(node.data)
        PreorderTraversal(node->left)
        PreorderTraversal(node->right)
    }
}
````
## Post-order traversal
````c++
void PostorderTraversal(TreeNode node)
{
    if(node != null)
    {
        PostorderTraversal(node->left)
        PostorderTraversal(node->right)
        printf(node.data)
    }
}
````
        


















