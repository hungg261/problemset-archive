<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### HUB01 - ĐOÀN THÁM HIỂM

Trên dãy núi có $n$ trạm dừng chân. Đoàn thám hiểm xuất phát từ trạm 1 và muốn vượt qua tất cả $n$ trạm lần lượt từ 1 đến $n$. Trạm thứ $i$ có độ cao $h_i$.

Do địa hình hiểm trở và nhiệt độ thấp nên nếu chênh lệch độ cao giữa 2 trạm liên tiếp vượt qua $D$ thì đoàn bắt buộc phải sử dụng thiết bị hỗ trợ để di chuyển. Để tiết kiệm năng lượng cho chuyến đi nên đoàn thám hiểm hạn chế sử dụng thiết bị hỗ trợ.

**Yêu cầu:** Tìm số lần tối thiểu phải sử dụng thiết bị hỗ trợ để di chuyển lần lượt từ trạm 1 đến trạm $n$.

#### Input

- Dòng 1: chứa 2 số nguyên $n$ và $D$ ($n \le 10^5; D \le 10^9$).
- Dòng 2: chứa $n$ số nguyên $h_1, h_2, ..., h_n$ ($1 \le h_i \le 10^9$).

#### Output

- Một số nguyên là số lần phải sử dụng thiết bị hỗ trợ.

#### Ví dụ
**Input #1:**
```
5 10
10 25 30 45 50
```

**Output #1:**
```
2
```

**Input #2:**
```
3 100
10 20 30
```

**Output #2:**
```
0
```

**Input #3:**
```
1 5
10
```

**Output #3:**
```
0
```

<!-- Footer -->
<div align="center">
<sub>Thi thử tuyển sinh 10 - PTNK Hub &bull; Phan Thành Hưng</sub>
</div>
