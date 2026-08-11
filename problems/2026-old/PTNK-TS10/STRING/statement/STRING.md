<div style="border:2px solid #999; border-radius:8px; padding:15px; box-sizing:border-box;">

### Bài 1: STRING

Cho xâu $S$ gồm các chữ cái Latin thường từ $\texttt{a}$ tới $\texttt{z}$.

Ta được phép xáo trộn tùy ý vị trí các ký tự trong xâu $S$, sau đó cắt xâu thành các đoạn con sao cho tất cả các đoạn con thu được đều là xâu đối xứng.

Mục tiêu là thực hiện việc cắt sao cho số lượng đoạn con tạo thành là ít nhất có thể.

#### Input

- Một dòng duy nhất chứa xâu ký tự $S$ ($1 \le |S| \le 10^6$) chỉ gồm các chữ cái Latin in thường.

#### Output

- Ghi ra một số nguyên duy nhất là số lượng đoạn con đối xứng ít nhất có thể chia được sau khi đã xáo trộn các ký tự.

#### Subtasks

- $20\%$: $|S| \le 9$, $S$ chỉ gồm các ký tự $\texttt{a}$ và $\texttt{b}$.
- $30\%$: $|S| \le 9$.
- $50\%$: Không có ràng buộc thêm. 

#### Ví dụ
**Input:**
```
abcadd
```

**Output:**
```
2
```

**Giải thích:**
Một cách sắp xếp và cắt thỏa mãn số xâu đối xứng cắt nhỏ nhất: $\texttt{cadbda} \rightarrow \texttt{c|adbda}$

<!-- Footer -->
<div align="center">
<sub>PTNK - Tuyển sinh 10 (2026) &bull; Phan Thành Hưng</sub>
</div>
