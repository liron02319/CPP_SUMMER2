# CPP_SUMMER2


## Overview

The project implements a tree data structure (`Tree`) in C++ with  iterators(`pre_order`, `post_order`, `in_order`, `bfs_scan`, `dfs_scan`, `heap`)

### Tree Class

The `Tree` class is a templated implementation of a k-ary tree, where:
- `T` is the type of data stored in each node.
- `D` is the degree of the tree (default is 2).

#### Methods

1. איטרטור Pre-Order - איטרטור הסורק את העץ בצורה הבאה: צומת נוכחית -> תת עץ שמאלי -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
2. איטרטור Post-Order - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> תת עץ ימני -> צומת נוכחית (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
3. איטרטור In-Order  - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> צומת נוכחית -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
5. איטרטור BFS - סריקת העץ לרוחב (משמאלי לימין) (עובד על עץ כללי).
6. איטרטור DFS - סריקת העץ בעזרת אלגוריתם DFS (עובד על עץ כללי).
7. איטרטור Heap - הפיכת עץ בינארי לערימת מינימום, לקריאה נוספת: https://he.wikipedia.org/wiki/%D7%A2%D7%A8%D7%99%D7%9E%D7%94_%D7%91%D7%99%D7%A0%D7%90%D7%A8%D7%99%D7%AA (פה אתם יכולים באלגוריתמים של הספרייה התקנית)
   
1. המתודה `add_root` - הוספת השורש של העץ. המתודה מקבלת צומת כלשהו ושמה אותו בשורש העץ.
2. המתודה `add_sub_node` - הוספת ילד לאב. המתודה מקבלת צומת בעץ וצומת כלשהו ויוצרת בן עבור אותו צומת.
3. המתודות `begin_pre_order`, `end_pre_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Pre-Order.
4. המתודות `begin_post_order`, `end_post_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Post-Order.
5. המתודות `begin_in_order`, `end_in_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת In-Order.
6. המתודות `begin_bfs_scan`, `end_bfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם BFS.
7. המתודות `begin_dfs_scan`, `end_dfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם DFS.
8. המתודה `myHeap`. המתודה הופכת עץ בינארי לערימת מינימום וחזירה איטרטורים עבור הערימה שהתקבלה.
9. יש לממש מפרק (Destructor) המוחק את כל העץ.
10. פונקציית הדפסה. ההדפסה תתבצע בעזרת GUI. עליכם ליצור ממשק שמדפיס את העץ על המסך בצורה הגיוניות לשיקולכם.


### Running main
their is a man with examples that do it and show on print / on GUI on Screen
For Example

![image](https://github.com/user-attachments/assets/85b1b4de-c16c-4042-a0b1-27e1010c874b)

![image](https://github.com/user-attachments/assets/c43fda0b-76c1-417a-b6ae-ad67352ba70c)


## Dependencies

- **SFML**: Required for GUI.


