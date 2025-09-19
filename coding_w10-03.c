#include <stdio.h>
#include <string.h> // ไลบรารีสำหรับฟังก์ชันเกี่ยวกับสตริง เช่น strcmp และ strlen

int main() {
    // ประกาศตัวแปรอาร์เรย์ของตัวอักษร (สตริง) เพื่อเก็บชื่อลูกค้า 2 ชื่อ
    // กำหนดขนาดไว้ที่ 100 ตัวอักษร เพื่อรองรับชื่อที่ค่อนข้างยาว
    char customer1[100];
    char customer2[100];

    // พิมพ์ข้อความเพื่อบอกให้ผู้ใช้ป้อนชื่อลูกค้าคนที่ 1
    printf("Enter name of customer 1: ");
    // ใช้ fgets เพื่อรับค่าจากผู้ใช้ ซึ่งปลอดภัยกว่าการใช้ scanf เพราะป้องกัน buffer overflow
    // และสามารถอ่านข้อความที่มีช่องว่างได้
    fgets(customer1, sizeof(customer1), stdin);

    // พิมพ์ข้อความเพื่อบอกให้ผู้ใช้ป้อนชื่อลูกค้าคนที่ 2
    printf("Enter name of customer 2: ");
    fgets(customer2, sizeof(customer2), stdin);

    // ฟังก์ชัน fgets จะเก็บอักขระขึ้นบรรทัดใหม่ ('\n') ไว้ที่ท้ายสตริง
    // เราจึงต้องลบมันออกเพื่อการเปรียบเทียบที่ถูกต้อง
    // strcspn ค้นหาตำแหน่งของ '\n' และเราก็แทนที่ด้วยอักขระ null ('\0') เพื่อสิ้นสุดสตริง
    customer1[strcspn(customer1, "\n")] = 0;
    customer2[strcspn(customer2, "\n")] = 0;

    // ใช้ฟังก์ชัน strcmp เพื่อเปรียบเทียบชื่อทั้งสอง
    // strcmp จะคืนค่าเป็น 0 ถ้าสตริงทั้งสองเหมือนกัน
    if (strcmp(customer1, customer2) == 0) {
        // กรณีที่ 1: ชื่อทั้งสองเหมือนกัน
        // แสดงผลตามที่ระบุในโจทย์
        printf("Both of your names are the same, which is %s.\n", customer1);
        // คำนวณและแสดงความยาวของชื่อ
        // strlen() จะคืนค่าจำนวนตัวอักษรในสตริง (ไม่นับอักขระ null ที่อยู่ท้ายสุด)
        printf("The length of the name is %d characters.\n", (int)strlen(customer1));
    } else {
        // กรณีที่2: ชื่อไม่เหมือนกัน
        // แสดงชื่อลูกค้าและจำนวนตัวอักษรของแต่ละชื่อตามตัวอย่าง output
        printf("Customer 1: %s (%d characters)\n", customer1, (int)strlen(customer1));
        printf("Customer 2: %s (%d characters)\n", customer2, (int)strlen(customer2));
    }

    return 0; // คืนค่า 0 เพื่อบอกว่าโปรแกรมทำงานเสร็จสิ้นอย่างสมบูรณ์
}