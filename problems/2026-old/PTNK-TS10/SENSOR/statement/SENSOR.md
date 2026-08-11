<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### Bài 2: SENSOR

Dọc theo một ống dẫn nước nóng, người ta lắp $n$ cảm biến nhiệt độ cách đều nhau, được đánh số từ 1 tới $n$. Cảm biến thứ $i$ đang hiển thị nhiệt độ đo được là $a_i$ (nhiệt độ). Nhiệt độ có xu hướng phụ thuộc vào vị trí trên đường ống, theo đó người ta tính toán được nhiệt độ trung bình về mặt lý thuyết của đoạn $[l; r]\ (1 \le l \le r \le n)$ là $l + r$. Để kiểm chứng, họ cần đếm số lượng đoạn phù hợp với lý thuyết.

Yêu cầu: Hãy đếm số đoạn cảm biến liên tiếp mà nhiệt độ trung bình đo được bằng với nhiệt độ trung bình về mặt lý thuyết. Cụ thể cần đếm số đoạn $[l; r]\ (1 \le l \le r \le n)$ thỏa mãn:

$$
\dfrac{a_l + a_{l + 1} + \dots + a_r}{r - l + 1} = l + r
$$

#### Input

- Dòng đầu tiên chứa số nguyên dương $n\ (1 \le n \le 3 \cdot 10^5)$.
- Dòng thứ hai chứa $n$ số nguyên $a_1, a_2, \cdots a_n\ (|a_i| \le 10^9)$.

#### Output

- Một dòng chứa số nguyên duy nhất là số đoạn thỏa mãn.

#### Subtasks

- $25\%$: $n \le 300$.
- $25\%$: $n \le 3000$.
- $50\%$: Không có ràng buộc thêm.

#### Ví dụ
**Input:**
```
3
3 3 6 
```

**Output:**
```
3
```

**Giải thích:**
Đoạn phù hợp là: $[1; 2], [1; 3], [3; 3]$.

<!-- Footer -->
<div align="center">
<sub>PTNK - Tuyển sinh 10 (2026) &bull; Phan Thành Hưng</sub>
</div>
