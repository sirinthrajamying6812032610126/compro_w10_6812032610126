#include <stdio.h>

int main() {
    // ใช้ 2D array (อาเรย์ 2 มิติ) เพื่อเก็บคะแนน
    // แถวแรกสำหรับนักเรียน (3 คน)
    // แถวที่สองสำหรับวิชา (คณิตศาสตร์, ฟิสิกส์, เคมี)
    // ใช้ 'float' เนื่องจากคะแนนอาจเป็นทศนิยมได้
    float scores[3][3];

    // สร้างอาเรย์ของข้อความ (string) เพื่อใช้แสดงชื่อวิชาและนักเรียนในผลลัพธ์
    const char *subjects[] = {"Math", "Physics", "Chemistry"};
    const char *students[] = {"Student 1", "Student 2", "Student 3"};

    // 1. รับค่าคะแนนจากผู้ใช้
    // ใช้ลูปซ้อนกันเพื่อวนรับคะแนนจากแต่ละวิชาของนักเรียนแต่ละคน
    printf("Enter scores for 3 students and 3 subjects (Math, Physics, Chemistry).\n");
    for (int i = 0; i < 3; i++) { // ลูปสำหรับนักเรียน
        printf("--- Enter scores for %s ---\n", students[i]);
        for (int j = 0; j < 3; j++) { // ลูปสำหรับวิชา
            printf("Enter %s score: ", subjects[j]);
            scanf("%f", &scores[i][j]);
        }
    }
    // 2. แสดงตารางคะแนน
    // จัดรูปแบบผลลัพธ์ให้เป็นตารางตามตัวอย่างในภาพ
    printf("\nScore Table:\n");
    printf("--------------------------------------------------\n");
    printf("Student\t\tMath\tPhysics\tChemistry\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        // แสดงหมายเลขนักเรียนและคะแนน
        printf("%d\t\t", i + 1); // หมายเลขนักเรียน (1, 2, 3)
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", scores[i][j]); // แสดงคะแนนพร้อมทศนิยม 2 ตำแหน่ง
        }
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    
    // 3. คำนวณและแสดงค่าเฉลี่ยของแต่ละวิชา
    printf("\nAverage per subject:\n");
    for (int j = 0; j < 3; j++) { // วนลูปสำหรับแต่ละวิชา
        float sum = 0.0;
        for (int i = 0; i < 3; i++) { // วนลูปสำหรับนักเรียนทุกคนเพื่อรวมคะแนน
            sum += scores[i][j];
        }
        // คำนวณค่าเฉลี่ยและแสดงผลพร้อมทศนิยม 2 ตำแหน่ง
        float average = sum / 3.0;
        printf("%s: %.2f\n", subjects[j], average);
    }

    return 0; // โปรแกรมทำงานเสร็จสิ้น
}