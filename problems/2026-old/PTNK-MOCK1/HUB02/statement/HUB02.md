<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### HUB02 - SỐ NGUYÊN TỐ CẶP

Số nguyên dương $X$ được gọi là "Nguyên tố cặp" nếu:
1. $X$ là một số nguyên tố.
2. Tồn tại ít nhất một vị trí chia $X$ thành 2 phần khác rỗng, mỗi phần đều tạo thành một số nguyên tố.

Ví dụ:
- 317 là nguyên tố cặp vì có thể chia thành 3 và 17, hoặc 31 và 7.
- 307 là nguyên tố cặp vì có thể chia thành 3 và 07 $\rightarrow$ tương đương 3 và 7.
- 29 không phải nguyên tố cặp vì chia thành 2 và 9 (9 không phải số nguyên tố).
- 103 không phải nguyên tố cặp vì (1, 3) và (10, 3) đều không phải cặp nguyên tố.

Yêu cầu: Cho hai số nguyên dương $L, R$. Hãy đếm số lượng số nguyên tố cặp trong đoạn $[L, R]$.

#### Input

- Dòng đầu chứa số nguyên $T$ ($1 \le T \le 10^5$) là số lượng test.
- Mỗi dòng trong $T$ dòng tiếp theo chứa 2 số $L, R$ ($1 \le L \le R \le 10^7$).

#### Output

- Gồm $T$ dòng, mỗi dòng ghi kết quả của bộ test tương ứng được cho trong dữ liệu vào.

#### Subtasks

- 25% số test: $T \le 100; 1 \le L \le R \le 1000$.
- 25% số test: $T \le 100; 1 \le L \le R \le 10^6$.
- 50% số test: không ràng buộc gì thêm.

#### Ví dụ
**Input:**
```
3
10 60
310 320
1 10
```

**Output:**
```
3
3
0
```

**Giải thích:**
Dòng 1: Có 3 số là 23, 37, 53.
Dòng 2: Có 3 số là 311, 313, 317.

<!-- Footer -->
<div align="center">
<sub>Thi thử tuyển sinh 10 - PTNK Hub &bull; Phan Thành Hưng</sub>
</div>
