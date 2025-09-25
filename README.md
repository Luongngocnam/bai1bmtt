# bai1bmtt
# BÀI TẬP 1:
# TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN  
Caesar  
Affine  
Hoán vị  
Vigenère  
Playfair  
# Với mỗi phương pháp, hãy tìm hiểu:  
Tên gọi  
Thuật toán mã hoá, thuật toán giải mã  
Không gian khóa  
Cách phá mã (mà không cần khoá)  
Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript  
# ============================

# Tên gọi: Mật mã Caesar.
Caesar cipher (một dạng shift cipher).
Thuật toán
Mã hoá: với khoá k (0..25). Với mỗi chữ cái P (A..Z): C = (P + k) mod 26.
Giải mã: P = (C - k + 26) mod 26.
Thường chỉ áp dụng trên chữ cái, giữ không thay đổi ký tự khác.
Không gian khoá
26 khả năng (k = 0..25).
Cách phá (không có khoá)
Brute-force: thử 26 khoá và chọn plaintext có nghĩa.
Phân tích tần suất: so sánh tần suất chữ cái.
# Hình ảnh kiểm thử  
# Mã hóa:
<img width="987" height="766" alt="image" src="https://github.com/user-attachments/assets/5236f456-b84e-4cdd-8caf-30788418ab12" />
# Giai mã :
<img width="1023" height="774" alt="image" src="https://github.com/user-attachments/assets/e7a05a3c-329e-4ea5-91ce-c98766e3f4f9" />

# Tên gọi: Mật mã Affine.
Tên gọi
Affine cipher (phép biến đổi tuyến tính trên modulo 26).
Thuật toán
Khoá gồm hai số (a, b) với 0 ≤ b ≤ 25 và a phải nguyên tố cùng nhau với 26 (gcd(a,26)=1) để tồn tại nghịch đảo modulo 26.
Mã hoá: C = (a * P + b) mod 26.
Giải mã: P = a^{-1} * (C - b) mod 26, trong đó a^{-1} là nghịch đảo của a modulo 26.
Không gian khoá
Số lượng a khả dụng: các số ≤25 mà gcd(a,26)=1. Với 26, các a hợp lệ là 1,3,5,7,9,11,15,17,19,21,23,25 → 12 giá trị. b có 26 khả năng → tổng 12*26 = 312 khóa.
Cách phá
Brute-force: thử 312 khả năng.
Phân tích tần suất có thể rút ra a và b (vì là biến đổi affine của phân phối tần suất).
# Hình ảnh kiểm thử  
# Mã hóa:
<img width="1002" height="613" alt="image" src="https://github.com/user-attachments/assets/b266848b-734f-446d-9ba6-37c3869a4870" />
# Giai mã :
<img width="1029" height="686" alt="image" src="https://github.com/user-attachments/assets/0770f7f8-1c76-4e10-bd60-f51088eca5e1" />

#  Tên gọi: Mật mã hoán vị.
Tên gọi
Columnar Transposition (một dạng hoán vị cột).
Thuật toán
Chọn một khóa dạng chuỗi (ví dụ "43152" hoặc từ chữ: "ZEBRAS") → quy định thứ tự cột.
Viết plaintext theo hàng vào một bảng có số cột = độ dài khoá, sau đó đọc theo thứ tự cột theo thứ tự khoá.
Giải mã: biết số cột, xây bảng và điền cột theo thứ tự khoá, sau đó đọc theo hàng.
Không gian khoá
Với khóa độ dài n, số hoán vị là n!. Nếu khoá là chuỗi có thể trùng lặp ký tự thì nhỏ hơn n!.
Cách phá
Brute-force trên hoán vị (với n nhỏ có thể).
Tấn công bằng phân tích mẫu (nhìn vào cấu trúc, khoảng trắng), hoặc kết hợp với tấn công thống kê/ngữ nghĩa.
# Hình ảnh kiểm thử  
# Mã hóa:
<img width="964" height="711" alt="image" src="https://github.com/user-attachments/assets/699126df-2cba-4f23-9583-3d48cc655e27" />
# Giai mã :
<img width="1011" height="777" alt="image" src="https://github.com/user-attachments/assets/3a91dc21-5927-4bc6-9e4c-49243348fe6e" />

# Tên gọi: Mật mã Vigenère.
Tên gọi
Vigenère cipher.
Thuật toán
Khoá là một chuỗi K = k0 k1 ... km-1 (kí tự A..Z). Xử lý plaintext P vị trí i bằng: C[i] = (P[i] + K[i mod m]) mod 26.
Giải mã: P[i] = (C[i] - K[i mod m] + 26) mod 26.
Không gian khoá
Tùy độ dài khoá m: 26^m.
Cách phá
Kasiski examination để ước lượng độ dài khoá.
Dùng phân tích tần suất trên các chuỗi con (chiến lược Friedman/Kasiski).
Brute-force độ dài ngắn.
# Hình ảnh kiểm thử  
# Mã hóa:
<img width="1064" height="802" alt="image" src="https://github.com/user-attachments/assets/693f507c-4dd5-4b0d-8c46-2bf7fb33c4be" />
# Giai mã :
<img width="1048" height="779" alt="image" src="https://github.com/user-attachments/assets/1fda67d2-215c-40ca-bdc2-27f279dcf8d0" />

# Tên gọi: Mật mã Playfair.
Tên gọi
Playfair cipher (ma trận 5×5, ghép cặp chữ cái).
Thuật toán (tóm tắt)
Tạo bảng 5×5 từ khóa: nối key + phần còn lại của bảng chữ cái A..Z (thường hợp nhất I/J — mình dùng I/J là một chữ cái: thường thay J bằng I).
Chia plaintext thành các digraphs (cặp): nếu trong một cặp hai chữ trùng nhau, chèn ký tự phụ (thường 'X') giữa chúng rồi tiếp tục; nếu cuối cùng thiếu 1 ký tự, thêm 'X'.
Với cặp (A,B):
Nếu cùng hàng: thay bằng chữ bên phải lần lượt (vòng vòng).
Nếu cùng cột: thay bằng chữ ở bên dưới lần lượt (vòng vòng).
Nếu khác hàng và khác cột: thay bằng hai chữ ở cùng hàng nhưng ở giao điểm cột (tạo hình chữ nhật): A' là chữ ở hàng A và cột B; B' là chữ ở hàng B và cột A.
Giải mã: thao tác ngược (trái / lên / rectangle).
Không gian khoá
Mỗi sắp xếp của 25 ký tự → 25! khả năng (rất lớn).
Cách phá
Phân tích digraph tần suất (phức tạp hơn monoalphabetic).
Brute-force không khả thi; các kỹ thuật heuristic (simulated annealing / hill-climbing) + tần suất tiếng để hồi phục key
# Hình ảnh kiểm thử  
# Mã hóa:
<img width="1056" height="787" alt="image" src="https://github.com/user-attachments/assets/3bf58353-78a2-442a-9586-5fff62216e4e" />
# Giai mã :
<img width="1012" height="773" alt="image" src="https://github.com/user-attachments/assets/0083197a-7d9b-451a-b8d3-6d4dcf39487f" />


