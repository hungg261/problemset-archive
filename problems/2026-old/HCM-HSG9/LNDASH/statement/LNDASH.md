<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### LNDASH - Trò chơi LineDash

Cho một nhân vật trong game di chuyển trên mặt phẳng tọa độ Oxy. Tại mỗi thời điểm, nhân vật thực hiện một trong ba loại hiệu lệnh sau:
- “/” : di chuyển đến ô $(x+1, y+1)$  
- “-” : di chuyển đến ô $(x+1, y)$  
- “\” : di chuyển đến ô $(x+1, y-1)$  

Ban đầu (tại thời điểm $1$), hiệu lệnh là “-”. Có $N$ lần thay đổi tín hiệu, mỗi lần thay đổi tại thời điểm $C_i$, hiệu lệnh sẽ được chuyển thành một trong ba loại trên. Hiệu lệnh sau khi thay đổi sẽ được giữ nguyên cho đến lần thay đổi tiếp theo.

Có $Q$ truy vấn, mỗi truy vấn thứ $i$ yêu cầu tính tổng quãng đường mà nhân vật đã di chuyển từ thời điểm $L_i$ đến $R_i$.

**Lưu ý quan trọng:**  
- Tại thời điểm $t$, nhân vật thực hiện **1 bước di chuyển** theo hiệu lệnh tại thời điểm đó.  
- Khi tính tổng quãng đường từ $L_i$ đến $R_i$, chỉ tính các bước từ $L_i \to L_i+1, L_i+1 \to L_i+2, …, R_i-1 \to R_i$.  
- Thời điểm $R_i$ không sinh thêm bước đi.

Kết quả cần được làm tròn đến đúng **6 chữ số thập phân**.

#### Input
- Dòng đầu tiên chứa ba số nguyên $N, T, Q\ (N, Q \le 10^5, T \le 10^9)$.  
- $N$ dòng tiếp theo, mỗi dòng gồm thời điểm $C_i$ và ký hiệu hiệu lệnh tại thời điểm đó $(0 \le C_1 < C_2 < \dots < C_N < T)$.  
- $Q$ dòng tiếp theo, mỗi dòng gồm hai số nguyên $L_i, R_i$ $(0 \le L_i, R_i \le N)$.

#### Output
- Gồm $Q$ dòng, mỗi dòng là kết quả của một truy vấn.

#### Subtasks
- **20% số điểm:** $N = 0$.  
- **20% số điểm:** $N = 1$, không có hiệu lệnh “-”.  
- **20% số điểm:** $N, T, Q \le 1000$.  
- **30% số điểm:** $T \le 10^5$.  
- **10% số điểm:** Không có ràng buộc gì thêm.

#### Ví dụ

**Input:**

```
3 5 2
1 /
3 -
4 \
1 5
2 4
```

**Output:**

```
5.242641
2.414214
```

**Giải thích:**


| Thời điểm $t$ | Hiệu lệnh |
|:-------------:|:---------:|
| 1             | /         |
| 2             | /         |
| 3             | -         |
| 4             | \         |
| 5             | \         |

Với lộ trình di chuyển là:
![Hình minh họa](minh_hoa.png)

- **Truy vấn `[1,5]`:**  
  Các bước đi: $1 \to 2$, $2 \to 3$, $3 \to 4$, $4 \to 5$  
  Quãng đường = $\sqrt{2} + \sqrt{2} + 1 + \sqrt{2} = 3\sqrt{2} + 1 = 5.242641$

- **Truy vấn `[2,4]`:**  
  Các bước đi: $2 \to 3$, $3 \to 4$  
  Quãng đường = $\sqrt{2} + 1 = 2.414214$

<!-- Footer -->
<div align="center">
<sub>HSG9-2026 &bull; Phan Thành Hưng</sub>
</div>

</div>