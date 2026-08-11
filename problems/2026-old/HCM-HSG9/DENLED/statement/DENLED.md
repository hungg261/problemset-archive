<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### DENLED - Hệ thống đèn Led

Cho một dãy gồm $n$ chiếc đèn LED, mỗi đèn thứ $i$ có công suất là một số nguyên dương $a_i$. Người ta muốn chọn ra một tập hợp các đèn (không nhất thiết phải liên tiếp nhau) sao cho tổng công suất của các đèn được chọn là **lớn nhất** và thỏa mãn các điều kiện sau:
- Tổng công suất chia hết cho một số nguyên dương $k$.
- Tổng công suất phải lớn hơn hoặc bằng $k$.

#### Input
- Dòng đầu tiên chứa hai số nguyên dương $n$ và $k$ ($1 \le n \le 1000, 1 \le k \le 100$).
- Dòng thứ hai chứa $n$ số nguyên dương $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

#### Output
- Một số nguyên duy nhất là tổng công suất lớn nhất tìm được. Nếu không có phương án nào thỏa mãn các điều kiện trên, in ra $0$.

#### Subtasks
- **30% số điểm:** $n \le 20, a_i \le 50$.
- **20% số điểm:** $n \le 1000, k = 2$.
- **20% số điểm:** $n \le 1000$, tổng của dãy $a \le 10^4$.
- **30% số điểm:** Không giới hạn gì thêm.

#### Ví dụ
**Input:**

```
3 6
10 2 4
```

**Output:**

```
12
```


**Giải thích:**
Các tập con có tổng chia hết cho $6$ và lớn hơn hoặc bằng $6$ là:
- Chọn đèn $\{10, 2\}$: Tổng là $10 + 2 = 12$ (thỏa mãn $12 \vdots 6$ và $12 \ge 6$).
- Chọn đèn $\{2, 4\}$: Tổng là $2 + 4 = 6$ (thỏa mãn $6 \vdots 6$ và $6 \ge 6$).

Trong các phương án, tổng lớn nhất tìm được là **12**.

<!-- Footer -->
<div align="center">
<sub>HSG9-2026 &bull; Phan Thành Hưng</sub>
</div>

</div>