<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### HUB04 - KONG

Trong khu rừng già, chú khỉ KONG đang thực hiện một hành trình trên một đường thẳng từ thời điểm $0$ đến thời điểm $T$. KONG có hai chế độ di chuyển:
- **Chế độ 1 (Leo trèo):** tốc độ $a$ mét/giây.
- **Chế độ 2 (Đu dây):** tốc độ $b$ mét/giây.

KONG bắt đầu hành trình (thời điểm $t = 0$) với **Chế độ 1**. Trong hành trình, KONG nhận được $n$ mệnh lệnh thay đổi chế độ. Mệnh lệnh thứ $i$ cho biết: tại thời điểm $t_i$, KONG chuyển sang chế độ $m_i$ và duy trì chế độ đó cho đến khi nhận được mệnh lệnh tiếp theo hoặc đến hết thời điểm $T$.

**Yêu cầu:** Cho $Q$ truy vấn, mỗi truy vấn gồm 2 số nguyên $L, R$ yêu cầu tính tổng quãng đường (đơn vị mét) mà KONG đã di chuyển từ giây thứ $L$ đến giây thứ $R$ (gồm cả giây $L$ và giây $R$).

#### Input

- Dòng đầu tiên chứa 5 số nguyên dương $n, T, Q, a, b$ ($1 \le n, Q \le 10^5; 1 \le T \le 10^9; 1 \le a, b \le 10^6$).
- $n$ dòng tiếp theo, dòng thứ $i$ chứa 2 số nguyên $t_i$ và $m_i$ ($0 \le t_i \le T; m_i \in \{1, 2\}$). Các $t_i$ được cho theo thứ tự tăng dần.
- $Q$ dòng tiếp theo, mỗi dòng chứa 2 số nguyên $L, R$ ($0 \le L < R \le T$).

#### Output

- Gồm $Q$ dòng, mỗi dòng chứa một số nguyên duy nhất là quãng đường tương ứng với truy vấn.

#### Subtasks

- 25% số test: $a = b$.
- 25% số test: $n, Q \le 1000$.
- 50% số test: không ràng buộc gì thêm.

#### Ví dụ
**Input:**
```
3 10 2 5 8
2 2 
5 1
8 2
0 5
3 9
```

**Output:**
```
34
39
```

**Giải thích:**
- Từ $t = 0$ đến $t = 2$ (2 giây): tốc độ 5, quãng đường $2 \times 5 = 10$ mét.
- Từ $t = 2$ đến $t = 5$ (3 giây): tốc độ 8, quãng đường $3 \times 8 = 24$ mét.
- Từ $t = 5$ đến $t = 8$ (3 giây): tốc độ 5, quãng đường $3 \times 5 = 15$ mét.
- Từ $t = 8$ đến $t = 9$ (1 giây): tốc độ 8, quãng đường $1 \times 8 = 8$ mét.

1. **Truy vấn [0, 5]:** Quãng đường là $10 + 24 = 34$.
2. **Truy vấn [3, 9]:** 
   - Từ $t = 3$ đến $t = 5$ (2 giây): tốc độ 8 $\rightarrow$ 16 mét.
   - Từ $t = 5$ đến $t = 8$ (3 giây): tốc độ 5 $\rightarrow$ 15 mét.
   - Từ $t = 8$ đến $t = 9$ (1 giây): tốc độ 8 $\rightarrow$ 8 mét.
   - Tổng cộng: $16 + 15 + 8 = 39$.

<!-- Footer -->
<div align="center">
<sub>Thi thử tuyển sinh 10 - PTNK Hub &bull; Phan Thành Hưng</sub>
</div>
