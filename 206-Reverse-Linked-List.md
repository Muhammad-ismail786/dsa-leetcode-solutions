# 206. Reverse Linked List

## Intuition

Is problem mein humein Singly Linked List ko reverse karna hai.

Example:

Original:
`1 → 2 → 3 → NULL`

Reversed:
`3 → 2 → 1 → NULL`

Iske liye hum 3 pointers use karenge:

1. **prev:** Previous Node ka address store karta hai. Starting mein `nullptr` hota hai.
2. **current:** Current Node ka address store karta hai. Starting mein `head` hota hai.
3. **next_node:** Agle Node ka address temporarily save karta hai, taake link reverse karte waqt agla Node lose na ho.

## Approach

Hum `while` loop use karenge jo tab tak chalega jab tak `current != nullptr` ho.

Har iteration mein 4 steps perform honge:

**Step 1: Next Node ka address save karna**

`next_node = current->next;`

Example:
- current = Node 1
- current->next = Node 2
- next_node = Node 2

**Step 2: Link reverse karna**

`current->next = prev;`

Node 1 ka next ab NULL ko point karega.

**Step 3: Previous pointer ko aage move karna**

`prev = current;`

Ab prev Node 1 ko point karega.

**Step 4: Current pointer ko next Node par move karna**

`current = next_node;`

Ab current Node 2 ko point karega.

Ye 4 steps har Node ke liye repeat honge.

### Dry Run

Original Linked List:

`1 → 2 → 3 → NULL`

| Iteration | current | next_node | prev |
|---|---|---|---|
| Start | Node 1 | NULL | NULL |
| 1 | Node 1 | Node 2 | Node 1 |
| 2 | Node 2 | Node 3 | Node 2 |
| 3 | Node 3 | NULL | Node 3 |
| End | NULL | NULL | Node 3 |

Final Linked List:

`3 → 2 → 1 → NULL`

`return prev;` use karte hain kyunke reverse hone ke baad prev naye first Node ko point karta hai.

## Complexity

- **Time Complexity:** O(n)

  Linked List ke har Node ko sirf aik baar visit karte hain.

- **Space Complexity:** O(1)

  Hum sirf 3 pointers (`prev`, `current`, `next_node`) use karte hain. Extra array ya Linked List create nahi karte.

## Code

See `206-Reverse-Linked-List.cpp` for the C++ solution.
