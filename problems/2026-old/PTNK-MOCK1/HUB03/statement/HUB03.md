<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### HUB03 - MOVE

Một robot di chuyển trong một bảng lưới ô vuông kích thước $m \times n$. Ô ở dòng $i$ và cột $j$ kí hiệu $(i, j)$. Khi di chuyển đến ô $(i, j)$, năng lượng của robot được tăng thêm $a_{ij}$ đơn vị.

Robot xuất phát từ ô $(1, 1)$ và di chuyển đến ô $(m, n)$. Tại mỗi bước, robot chỉ được phép di chuyển sang ô chung cạnh bên phải hoặc ô chung cạnh bên dưới.

Để kích hoạt cổng thoát tại ô $(m, n)$ và hoàn thành lộ trình, tổng năng lượng mà robot thu thập được trên toàn bộ lộ trình là lớn nhất và chia hết cho $k$.

**Yêu cầu:** Tìm tổng năng lượng lớn nhất mà robot nhận được trên lộ trình thỏa yêu cầu.

#### Input

- Dòng đầu tiên chứa 3 số nguyên dương $m, n, k$ ($1 \le m, n \le 500; 1 \le k \le 200$).
- Dòng thứ $i$ trong $m$ dòng tiếp theo chứa $n$ số nguyên, số thứ $j$ là $a_{ij}$ ($1 \le a_{ij} \le 10^6$).

#### Output

- Một số nguyên là tổng năng lượng lớn nhất chia hết cho $k$. Nếu không tồn tại lộ trình thỏa yêu cầu thì in ra $-1$.

#### Subtasks

- 20% số test: $m, n, k \le 10$.
- 30% số test: $m, n \le 500; k = 1$.
- 50% số test: không ràng buộc gì thêm.

#### Ví dụ
**Input #1:**
```
5 7 11
2 5 3 1 8 4 6
7 1 9 2 5 3 1
4 6 2 8 1 7 5
9 3 5 1 4 2 8
1 7 4 6 2 9 3
```

**Output #1:**
```
44
```


**Input #2:**
```
5 7 30
2 5 3 1 8 4 6
7 1 9 2 5 3 1
4 6 2 8 1 7 5
9 3 5 1 4 2 8
1 7 4 6 2 9 3
```

**Output #2:**
```
-1
```


<!-- Footer -->
<div align="center">
<sub>Thi thử tuyển sinh 10 - PTNK Hub &bull; Phan Thành Hưng</sub>
</div>
