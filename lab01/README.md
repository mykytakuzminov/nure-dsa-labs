# Binary Search Tree — Lab 1

**Discipline:** Algorithms and Data Structures  
**Variant:** No. 8  
**Student:** Mykyta Kuzminov  
**Group:** ІТШІ-25-1  

## Objective

Study the fundamental algorithms for constructing and processing Binary Search Trees (BST), including manual step-by-step tree building, range search queries, node deletion, and programmatic implementation of core dictionary operations.

## Tasks

1. Manually perform step-by-step insertion of nodes with keys `30, 40, 50, 24, 8, 58, 48, 26, 11, 13`
2. Perform a range search query for `[12; 45]`
3. Perform deletion of nodes `48, 11, 13`
4. Programmatically implement: `Search`, `Successor`, `Predecessor`, `Insert`, `Delete`, `GetInorderWalk`, `GetRange`
5. Performance experiment with 1,000,000 random elements and 200,000 mixed operations

## Results

### Task 1

> The images below illustrate building a tree from scratch. The first element becomes the root, while subsequent values are placed left (if smaller) or right (if larger).

<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/827afdfc-8224-4845-b1ad-ad2a4c9815eb" /></td>
    <td><img src="https://github.com/user-attachments/assets/4e0c4d95-0807-475c-8d5b-dfab469565b3" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/8654c023-0d91-42c2-a7d0-dd0cc53d84be" /></td>
    <td><img src="https://github.com/user-attachments/assets/2fb1a7be-a584-48de-8a96-7d7939b97f9e" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/5e6b8333-ca8e-4c81-9a2b-7c8a123272ec" /></td>
    <td><img src="https://github.com/user-attachments/assets/df982c36-af60-4514-837a-3238d94d7622" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/c6ca8b13-b08b-46e1-ba38-aa4110e4b5d1" /></td>
    <td><img src="https://github.com/user-attachments/assets/742c48b1-ef1b-4505-8928-2568c0511ea0" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/55723112-b7c8-4500-9f96-193021facfa8" /></td>
    <td><img src="https://github.com/user-attachments/assets/dd172a26-a994-46da-ac5d-c443502a2599" /></td>
  </tr>
</table>

### Task 2

> Images below show getting a range of elements with provided range borders. Green color shows the elements that are included while orange color ones are not. To ensure an ordered result, an in-order traversal is applied.

<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/3d0f25bb-fcec-44f0-9972-8d70ea3aeda5" /></td>
    <td><img src="https://github.com/user-attachments/assets/9def7cef-d452-4309-9d58-c42571b624e9" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/a34e95cb-b22e-4185-825e-7c5e10dbce32" /></td>
    <td><img src="https://github.com/user-attachments/assets/e649bde8-68bf-4a9e-bc18-c9d4911ad624" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/c18d1ae8-dfab-423e-b2dc-d24810eae314" /></td>
    <td><img src="https://github.com/user-attachments/assets/a5d60fec-2355-42df-9d64-2cdb4e17262b" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/3e58b09e-9bab-4c68-ab8c-cdaebf333ce1" /></td>
    <td><img src="https://github.com/user-attachments/assets/660cca95-da74-4e2e-9e2a-b806468d6b46" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/f245013f-8c43-4511-ab41-14cbcb8b67b6" /></td>
    <td><img src="https://github.com/user-attachments/assets/cd7dfe39-5065-474f-9455-6c2d39b4de57" /></td>
  </tr>
</table>

### Task 3

> Images below show deleting elements from variant No. 8 (48, 11, 13). There are four removal cases. First, if a node has no children, we simply remove it. If it has either a left or right child, we replace the node with that child. Finally, if both branches exist, we replace the node with the smallest value from the right subtree. This logic works because right-side nodes are always larger.

<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/fd73197c-84ec-45ac-a67d-dc61d19e4ebd" /></td>
    <td><img src="https://github.com/user-attachments/assets/7bd66744-4c10-459f-bd7f-fc50007c8727" /></td>
  </tr>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/93394a16-fc5a-4c0d-ad30-bf129a4f4ee4" /></td>
    <td><img src="https://github.com/user-attachments/assets/5eba1a8e-90b6-482a-b90b-33d6095bb674" /></td>
  </tr>
</table>

### Task 4

> Programmatically implemented the BinarySearchTree class with root and size properties. The root one contains a pointer to the main node of the tree. The size property is used to get the size of a tree with O(1) complexity. Moreover BTS class contains the realizations of structures Node and SearchResult. The first one represents a fundamental component of the tree that contains a value and two pointers on its children. The second one is used to ensure efficient data retrieval. There are basic methods such as Insert(), Delete(), Height(), Size(), Search(), Successor(), Predecessor(), GetInorderWalk() and GetRange().

<img src="https://github.com/user-attachments/assets/55e272be-c1b7-47f1-9d05-277909708d91" />

*Figure 1.1 – Basic tree operations test*

### Task 5

> To evaluate performance, a BST was filled with one million random numbers and tested against the theoretical log2​(n) ideal. While a 1.0 ratio represents perfect balance, our results showed operational ratios between 1.33 and 1.49, with a height ratio around 2.4–2.9. This indicates that despite the tree being nearly three times the ideal height, actual search efficiency remains high, requiring only 30–50% more operations than the theoretical minimum.

*Each run represents an average over 10 × 200,000 mixed operations on a BST of 1,000,000 elements.*

<img src="https://github.com/user-attachments/assets/d425d24a-3f79-4278-a288-0c3ef64f616f" />

*Figure 1.2 – Standard BST metrics No. 1*

<img src="https://github.com/user-attachments/assets/c3cf8788-2ef4-42cb-ab27-2d89abaaa3fb" />

*Figure 1.3 – Standard BST metrics No. 2*

<img src="https://github.com/user-attachments/assets/ecf48dae-c916-4e58-84b8-53fb434d94f5" />

*Figure 1.4 – Standard BST metrics No. 3*

<img src="https://github.com/user-attachments/assets/1126ad87-bd57-427a-b7bf-59235c2fb0ca" />

*Figure 1.5 – Standard BST metrics No. 4*

### Performance metrics
| Run | Height ratio | Search ratio | Insert ratio | Delete ratio |
|-----|-------------|--------------|--------------|--------------|
| 1   | 2.92        | 1.49         | 1.49         | 1.50         |
| 2   | 2.71        | 1.48         | 1.48         | 1.48         |
| 3   | 2.42        | 1.39         | 1.39         | 1.39         |
| 4   | 2.52        | 1.34         | 1.34         | 1.34         |

## Conclusion

Despite the tree height being approximately 2.4–2.9× the theoretical ideal (log₂n), actual operations required only 30–50% more visits than a perfectly balanced tree, confirming that BST remains practical for random data.
