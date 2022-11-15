#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
 
using namespace std;
 
const int WIDTH = 18;
 
class SinhVien {
private:
	string mssv;
	string hoVaTen;
	double toan, ly, hoa, DTB;
public:
	SinhVien(string mssv, string hoVaTen, double toan, double ly, double hoa) {
		this->mssv = mssv;
		this->hoVaTen = hoVaTen;
		this->toan = toan;
		this->ly = ly;
		this->hoa = hoa;
		DTB = round((toan + ly + hoa) / 3 * 100) / 100;
	}
	SinhVien() {}
 
	string getMssv() {
		return mssv;
	}
 
	string getHoVaTen() {
		return hoVaTen;
	}
 
	double getToan() {
		return toan;
	}
 
	double getLy() {
		return ly;
	}
 
	double getHoa() {
		return hoa;
	}
 
	double getDTB() {
		return DTB;
	}
 
	void nhap() {
		cout << "Ma so sinh vien: ";
		// getline de nhap chuoi 
		getline(cin, this->mssv);
 
 
		cout << "Ho va ten: ";
		getline(cin, this->hoVaTen);
 
		cout << "Diem toan: ";
		cin >> toan;
 
		cout << "Diem ly: ";
		cin >> ly;
 
		cout << "Diem hoa: ";
		cin >> hoa;
 
		DTB = (toan + ly + hoa) / 3;
	}
 
 
};
 
struct Node {
	SinhVien sv;
	Node* next;
	Node(SinhVien sv) {
		this->sv = sv;
		this->next = NULL;
	}
};
 
class DanhSachLienKetDon {
private:
 	Node* head;
public:
	DanhSachLienKetDon() {
		this->head = NULL;
	}
 
	// 2
	void xuat() {
		cout << setw(WIDTH) << "Ma sinh vien" << "|"
			<< setw(WIDTH) << "Ho va ten" << "|"
			<< setw(WIDTH) << "Toan" << "|"
			<< setw(WIDTH) << "Ly" << "|"
			<< setw(WIDTH) << "Hoa" << "|"
			<< setw(WIDTH) << "Diem trung binh" << endl;
		Node* temp = head;	
		while (temp != NULL) {
			cout << setw(WIDTH) << temp->sv.getMssv() << "|"
				<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
				<< setw(WIDTH) << temp->sv.getToan() << "|"
				<< setw(WIDTH) << temp->sv.getLy() << "|"
				<< setw(WIDTH) << temp->sv.getHoa() << "|"
				<< setw(WIDTH) << temp->sv.getDTB() << endl;
			temp = temp->next;
		}
	}
 
	// 3
	void sinhVienXepLoaiYeu() {
		cout << setw(WIDTH) << "Ma sinh vien" << "|"
			<< setw(WIDTH) << "Ho va ten" << "|"
			<< setw(WIDTH) << "Toan" << "|"
			<< setw(WIDTH) << "Ly" << "|"
			<< setw(WIDTH) << "Hoa" << "|"
			<< setw(WIDTH) << "Diem trung binh" << endl;
		Node* temp = head;
		while (temp != NULL) {
			if (temp->sv.getDTB() < 4) {
				cout << setw(WIDTH) << temp->sv.getMssv() << "|"
					<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
					<< setw(WIDTH) << temp->sv.getToan() << "|"
					<< setw(WIDTH) << temp->sv.getLy() << "|"
					<< setw(WIDTH) << temp->sv.getHoa() << "|"
					<< setw(WIDTH) << temp->sv.getDTB() << endl;
			}
			temp = temp->next;
		}
	}
 
 
	// 4
	void sinhVienCoDTBTren5() {
		cout << setw(WIDTH) << "Ma sinh vien" << "|"
			<< setw(WIDTH) << "Ho va ten" << "|"
			<< setw(WIDTH) << "Toan" << "|"
			<< setw(WIDTH) << "Ly" << "|"
			<< setw(WIDTH) << "Hoa" << "|"
			<< setw(WIDTH) << "Diem trung binh" << endl;
		Node* temp = head;
		while (temp != NULL) {
			if (temp->sv.getDTB() > 5) {
				cout << setw(WIDTH) << temp->sv.getMssv() << "|"
					<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
					<< setw(WIDTH) << temp->sv.getToan() << "|"
					<< setw(WIDTH) << temp->sv.getLy() << "|"
					<< setw(WIDTH) << temp->sv.getHoa() << "|"
					<< setw(WIDTH) << temp->sv.getDTB() << endl;
			}
			temp = temp->next;
		}
	}
 
	void themDau(SinhVien sv) {
		Node* newNode = new Node(sv);
		if (head == NULL) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode; 
		}
	}
 
	void themCuoi(SinhVien sv) {
		Node* newNode = new Node(sv);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* currentNode = head;
			while (currentNode->next != NULL) {
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
	}
 
	// 6
	void xoaDau() {
		if (head == NULL) {
			return;
		}
		Node* headNode = head;
		head = head->next;
		delete headNode;
	}
 
	// 7
	void xoaCuoi() {
		if (head == NULL) {
			return;
		}
		// khi co 1 thang trong day
		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		Node* currentNode = head;
		while (currentNode->next->next != NULL) {
			currentNode = currentNode->next;
		}
		Node* delNode = currentNode->next;
		currentNode->next = NULL;
		delete delNode;
	}
 
 
	// 8
	void xoaToanBoDanhSach() {
		if (head == NULL) {
			return;
		}
 
		Node* currentNode = head;
		while (head != NULL) {
			head = head->next;
			delete currentNode;
			currentNode = head;
		}
		delete head;
		head == NULL;
	}
 
 
	// 5
	SinhVien timSinhVienTheoMa(string mssv) {
		SinhVien sinhVienTraVe;
		Node* temp = head;
		while (temp != NULL) {
			if (temp->sv.getMssv() == mssv) {
				cout << setw(WIDTH) << "Ma sinh vien" << "|"
					<< setw(WIDTH) << "Ho va ten" << "|"
					<< setw(WIDTH) << "Toan" << "|"
					<< setw(WIDTH) << "Ly" << "|"
					<< setw(WIDTH) << "Hoa" << "|"
					<< setw(WIDTH) << "Diem trung binh" << endl;
				cout << setw(WIDTH) << temp->sv.getMssv() << "|"
					<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
					<< setw(WIDTH) << temp->sv.getToan() << "|"
					<< setw(WIDTH) << temp->sv.getLy() << "|"
					<< setw(WIDTH) << temp->sv.getHoa() << "|"
					<< setw(WIDTH) << temp->sv.getDTB() << endl;
					sinhVienTraVe = temp->sv;
					return sinhVienTraVe;
			}
			temp = temp->next;
		}
		cout << "Khong tim thay sinh vien" << endl;
		return sinhVienTraVe;
	}
 
	void initData() {
		SinhVien sv1("A12345", "Nguyen Van A", 1, 2, 3);
		SinhVien sv2("B12346", "Nguyen Van B", 7, 6, 7);
		SinhVien sv3("C12345", "Nguyen Van C", 6, 1, 2);
		SinhVien sv4("D12345", "Nguyen Van D", 1, 2, 3);
		SinhVien sv5("E12346", "Nguyen Van E", 1, 1, 1);
		SinhVien sv6("123457", "Nguyen Van F", 10, 10, 9);
		SinhVien sv7("C12345", "Nguyen Van C", 3, 2, 1);
		this->themCuoi(sv1);
		this->themCuoi(sv2);
		this->themCuoi(sv3);		
		this->themCuoi(sv4);
		this->themCuoi(sv5);
		this->themCuoi(sv6);
		this->themCuoi(sv7);
	}
};
 
 
int main() {
	DanhSachLienKetDon ds;
	ds.initData();
	int luaChon = -1;
	while (luaChon != 0) {
		system("cls");
		cout << "1 . Them sinh vien vao dau danh sach" << endl;
		cout << "2 . Them sinh vien vao cuoi danh sach" << endl;
		cout << "3 . Xoa sinh vien dau danh sach" << endl;
		cout << "4 . Xoa sinh vien cuoi danh sach" << endl;
		cout << "5 . Xuat danh sach sinh vien" << endl;
		cout << "6 . Xuat danh sach sinh vien xep loai yeu" << endl;
		cout << "7 . Xuat danh sach sinh vien co diem trung binh tren 5" << endl;
		cout << "8. Tim sinh vien theo ma sinh vien" << endl;
		cout << "9. Xoa toan bo sinh vien" << endl;
		cout << "0 . Ket thuc chuong trinh" << endl;
		cout << "Lua chon: ";
		cin >> luaChon;
		cin.ignore();
		switch (luaChon)
		{
		case 1: {
			SinhVien sv;
			sv.nhap();
			ds.themDau(sv);
			break;
		}
		case 2: {
			SinhVien sv;
			sv.nhap();
			ds.themCuoi(sv);
			break;
		}
		case 3: {
			ds.xoaDau();
			break;
		}
		case 4: {
			ds.xoaCuoi();
			break;
		}
		case 5: {
			ds.xuat();
			system("pause");
			break;
		}
		case 6: {
			ds.sinhVienXepLoaiYeu();
			system("pause");
			break;
		}
		case 7: {
			ds.sinhVienCoDTBTren5();
			system("pause");
			break;
		}
		case 8: {
			string mssv;
			cout << "Nhap ma sinh vien: ";
			cin >> mssv;
			ds.timSinhVienTheoMa(mssv);
			system("pause");
			break;
		}
		case 9: {
			ds.xoaToanBoDanhSach();
			break;
		}
		default:
			break;
		}
	}
}
