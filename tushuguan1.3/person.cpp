#include "person.h"
#include "book.h"

void person::mainmenu()
{
    cout << "---------------------------------" << endl;
    cout << "--------1.��¼-------------------" << endl;
    cout << "--------2.����-------------------" << endl;
    cout << "--------3.ϵͳ˵��---------------" << endl;
    cout << "--------4.�����Ϣ---------------" << endl;
    cout << "--------5.�˳�ϵͳ---------------" << endl;
    cout << "--------6.ע��-------------------" << endl;
    cout << "--------7.����Ա��¼-------------" << endl;
    cout << "---------------------------------" << endl;
}

void person::denglumenu()
{
    cout << "---------------------------------" << endl;
    cout << "--------1.����-------------------" << endl;
    cout << "--------2.����-------------------" << endl;
    cout << "--------3.�޸�����---------------" << endl;
    cout << "--------4.�˳�-------------------" << endl;
    cout << "---------------------------------" << endl;

}


void manager::managermenu()
{
    cout << "---------------------------------------------------" << endl;
    cout << "--------------1.�鿴���ж�����Ϣ-------------------" << endl;
    cout << "--------------2.���ȫ��������Ϣ-------------------" << endl;
    cout << "--------------3.�������---------------------------" << endl;
    cout << "--------------4.ɾ���鼮---------------------------" << endl;
    cout << "--------------5.�޸��鼮---------------------------" << endl;
    cout << "--------------6.�˳�����Աϵͳ---------------------" << endl;
    cout << "---------------------------------------------------" << endl;
}
person::person()
{}

void person::denglu()
{
    int zhanghao, mima;
    //�����˺�
    cout << "��������˺�" << endl;
    cin >> zhanghao;
    //��������
    cout << "�����������" << endl;
    cin >> mima;
    m2.insert(pair<int, int>(zhanghao, mima));
        if (m1!=m2)
        {
            cout << "�û��˺��������" << endl;
        }
        else
        {
            this->denglumenu();
            switch (getchar())
            {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                exit(0);
                break;
            default:
                cout << "�޷�����" << endl;
                break;
            }
        }
}


void student::zhuce()
{
    //ע���˺�
    cout << "��������ע����˺�" << endl;
     int id;
     cin >> id;
    //ע������
     cout << "��������ע�������" << endl;
     int key1;
     cin >> key1;
     cout << "�ٴ�ȷ����ע�������" << endl;
     int key2;
     cin >> key2;
     if (key1 != key2)
     {
         cout << "�������벻һ���޷�ע��" << endl;
         return;
     }
     else
     {
         m1.insert(pair<int, int>(id, key1));
     }
}    


void manager::managerdenglu()
{
    //��¼�ɹ��жϺ���
    int zhanghao1, mima1, win;
    int zhanghao2 = 147258;
    int mima2 = 123456;
    cout << "�������˺�" << endl;
    cin >> zhanghao1;
    cout << "����������" << endl;
    cin >> mima1;
    if (zhanghao1 == zhanghao2 && mima1 == mima2)
    {
        win = 1;
    }
    else
    {
        cout << "����Ա�˺��������" << endl;
        return;
    }
    //����Ա��¼�ɹ�
    while (win == 1)
    {
        this->managermenu();
        //�����Ŷ�Ӧ�˵����ֱ��
        switch (getchar())
        {
        case '1':
            break;
        case '2':
            break;
        case '3'://�������
            this->newbook();
            break;
        case '4'://ɾ���鼮
            this->delbook();
            break;
        case '5'://�޸��鼮
            this->changebook();
            break;
        case '6'://�˳�����Աϵͳ
            exit(0);
            break;
        default:
            cout << "�޷�����" << endl;
            break;
        }
    }
}

void manager::newbook()//����Ա�����鼮
{
    
    cout << "������ͼ������" << endl;
    cin >> bookname;
    cout << "������ͼ������" << endl;
    cin >> neirong;
    book.insert(make_pair(bookname, neirong));
}


void manager::delbook()//����Աɾ���鼮
{
    string name;
    cout << "--------------------------" << endl;
    cout << "-----1.ɾ����ѡ�鼮-------" << endl;
    cout << "-----2.ɾ��ȫ���鼮-------" << endl;
    cout << "--------------------------" << endl;
    switch (getchar())
    {
    case '1':
        cout << "����������ɾ���鼮������" << endl;
        cin >> name;
        book.erase(bookname);
        break;
    case '2':
        book.clear();
        break;
    default:
        break;
    }

}


void manager::changebook()
{
    cout << "�����������޸��鼮������" << endl;
    cin >> bookname;
    cout << "�������޸ĺ������" << endl;
    cin >> neirong;
    book.insert(make_pair(bookname, neirong));
}