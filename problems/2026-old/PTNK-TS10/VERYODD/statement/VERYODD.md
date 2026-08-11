<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### Bài 3: VERYODD

Số nguyên dương $m > 1$ được gọi là "số rất lẻ" nếu các ước dương của $m$ (kể cả chính nó) có thể được viết lên một vòng tròn theo một thứ tự nào đó sao cho tổng của hai số đứng cạnh nhau luôn là một số lẻ.

Ngoài ra, tổng của tất cả các ước dương của $m$ cũng phải là số lẻ.

Ví dụ, $18$ là một số rất lẻ vì các ước của nó là:
$$
1,\,2,\,3,\,6,\,9,\,18.
$$

Có thể viết chúng lên vòng tròn theo thứ tự trên, khi đó tổng của hai số đứng cạnh nhau luôn là số lẻ. Đồng thời, tổng các ước của chúng cũng là số lẻ:
$$
1 + 2 + 3 + 6 + 9 + 18 = 39,
$$
mà $39$ cũng là số lẻ.

Yêu cầu: cho $q$ truy vấn. Mỗi truy vấn gồm một số nguyên dương $n$.

Hãy in ra số lượng số rất lẻ là ước của $n$.

#### Input

- Dòng đầu tiên chứa số nguyên dương $q$ ($q \le 10$) - số lượng truy vấn.
- $q$ dòng tiếp theo, mỗi dòng chứa một số nguyên dương $n$ ($1 \le n \le 10^{18}$).

#### Output

- Ghi ra $q$ dòng, mỗi dòng một số nguyên duy nhất là câu trả lời cho truy vấn tương ứng.

#### Subtasks

- $20\%$ số điểm: $n \le 10^3$.
- $25\%$ số điểm: $n \le 10^6$.
- $25\%$ số điểm: $n \le 10^{12}$.
- $30\%$ số điểm: Không có ràng buộc thêm.

#### Ví dụ
**Input:**
```
3
18
30
7
```

**Output:**
```
2
1
0
```

**Giải thích:**
- Với $n = 18$: Có $2$ ước là số rất lẻ là $2$ và $18$.
- Với $n = 30$: Có $1$ ước là số rất lẻ là $2$.
- Với $n = 7$: Không có ước nào thỏa mãn tính chất số rất lẻ.

<!-- Footer -->
<div align="center">
<sub>PTNK - Tuyển sinh 10 (2026) &bull; Phan Thành Hưng</sub>
</div>
