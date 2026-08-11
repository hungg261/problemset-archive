<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### Bài 4: EXPLORE

Cho ma trận kích thước $n \times m$. Nhân vật phải di chuyển từ vị trí bắt đầu đến vị trí kết thúc theo chỉ định, bằng cách thực hiện các bước dịch chuyển tức thời từ ô $(x, y)$ đến ô $(z, t)$ thuộc bảng nếu thỏa mãn điều kiện $(z - x)^2 + (t - y)^2 = d_i$ với $d_i$ là một trong $k$ loại dịch chuyển cho trước.

Có thử thách:
- Cùng lúc với mỗi lượt nhân vật di chuyển, con sói cũng có thể đứng yên hoặc đi sang các ô chung cạnh với ô hiện tại của nó (trong phạm vi bảng). Nếu sau một lượt đi nào đó, nhân vật và sói đứng chung một ô thì nhân vật sẽ chết (cho dù ô đó là ô đích).
- Một số ô bị cấm, không ai được phép đi vào (cả sói và nhân vật).
- Sói ngụy trang rất tốt nên nhân vật chỉ biết được vị trí ban đầu của nó.

Lưu ý rằng cũng có thể có nhiều con sói trong ma trận.

Yêu cầu: tìm ít lượt di chuyển nhất để về đích, nếu không có cách nào thì in $-1$.

#### Input

- Dòng đầu tiên gồm ba số nguyên $n, m$ và $k$ ($1 \le n, m \le 500$, $1 \le k \le 26$).
- $n$ dòng tiếp theo, mỗi dòng chứa một chuỗi gồm $m$ ký tự mô tả ma trận bảng:
  - `.` : Ô trống mà nhân vật và sói có thể đi vào.
  - `#` : Ô tường cấm, không ai được phép đi vào.
  - `s` : Vị trí xuất phát của nhân vật.
  - `t` : Vị trí đích đến của nhân vật.
  - `w` : Vị trí ban đầu của sói.
- Dòng cuối cùng chứa $k$ số nguyên $d_1, d_2, \dots, d_k$ ($1 \le d_1 < d_2 < \dots < d_k \le 26$) là khoảng cách bình phương của các loại dịch chuyển.

#### Output

- Một số nguyên duy nhất là số lượt di chuyển ít nhất để nhân vật về đích an toàn, hoặc in ra $-1$ nếu không có kế hoạch di chuyển nào khả thi.

#### Subtasks

- $8\%$: $k = 1, d = 1$, không có ô `w` và không có ô `#`.
- $20\%$: $k = 1, d = 5$, không có ô `w` và không có ô `#`.
- $20\%$: không có ô `w`.
- $24\%$: có đúng 1 ô `w`.
- $28\%$: Không có ràng buộc thêm.

#### Ví dụ
**Input:**
```
2 5 2
s..#.
w..#t
1 5
```

**Output:**
```
3
```

**Giải thích:**
Nhân vật di chuyển như sau:
$(1, 1) \rightarrow (2, 3) \rightarrow (1, 5) \rightarrow (2, 5)$.

<!-- Footer -->
<div align="center">
<sub>PTNK - Tuyển sinh 10 (2026) &bull; Phan Thành Hưng</sub>
</div>
