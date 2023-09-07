#include "person.h"
#include "book.h"

void person::mainmenu()
{
    cout << "---------------------------------" << endl;
    cout << "--------1.登录-------------------" << endl;
    cout << "--------2.帮助-------------------" << endl;
    cout << "--------3.系统说明---------------" << endl;
    cout << "--------4.书库信息---------------" << endl;
    cout << "--------5.退出系统---------------" << endl;
    cout << "--------6.注册-------------------" << endl;
    cout << "--------7.管理员登录-------------" << endl;
    cout << "---------------------------------" << endl;
}

void person::denglumenu()
{
    cout << "---------------------------------" << endl;
    cout << "--------1.借书-------------------" << endl;
    cout << "--------2.还书-------------------" << endl;
    cout << "--------3.修改密码---------------" << endl;
    cout << "--------4.退出-------------------" << endl;
    cout << "---------------------------------" << endl;

}


void manager::managermenu()
{
    cout << "---------------------------------------------------" << endl;
    cout << "--------------1.查看所有读者信息-------------------" << endl;
    cout << "--------------2.清空全部读者信息-------------------" << endl;
    cout << "--------------3.新书入库---------------------------" << endl;
    cout << "--------------4.删除书籍---------------------------" << endl;
    cout << "--------------5.修改书籍---------------------------" << endl;
    cout << "--------------6.退出管理员系统---------------------" << endl;
    cout << "---------------------------------------------------" << endl;
}
person::person()//构造函数
{}

void student::denglu()
{
    int zhanghao, mima;
    //输入账号
    cout << "输入你的账号" << endl;
    cin >> zhanghao;
    //输入密码
    cout << "输入你的密码" << endl;
    cin >> mima;
    m2.insert(pair<int, int>(zhanghao, mima));
        if (m1!=m2)
        {
            cout << "用户账号密码错误" << endl;
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
                this->change();
                break;
            case '4':
                exit(0);
                break;
            default:
                cout << "无法操作" << endl;
                break;
            }
        }
}


void student::zhuce()
{
    //注册账号
    cout << "请输入你注册的账号" << endl;
     cin >> id;
    //注册密码
     cout << "请输入你注册的密码" << endl;
     cin >> key1;
     cout << "再次确认你注册的密码" << endl;
     cin >> key2;
     if (key1 != key2)
     {
         cout << "两次密码不一致无法注册" << endl;
         return;
     }
     else
     {
         m1.insert(pair<int, int>(id, key1));
     }
}    


void manager::managerdenglu()
{
    //登录成功判断函数
    int zhanghao1, mima1, win;
    int zhanghao2 = 147258;
    int mima2 = 123456;
    cout << "请输入账号" << endl;
    cin >> zhanghao1;
    cout << "请输入密码" << endl;
    cin >> mima1;
    if (zhanghao1 == zhanghao2 && mima1 == mima2)
    {
        win = 1;
    }
    else
    {
        cout << "管理员账号密码错误" << endl;
        return;
    }
    //管理员登录成功
    while (win == 1)
    {
        this->managermenu();
        //下面编号对应菜单数字编号
        switch (getchar())
        {
        case '1':
            break;
        case '2':
            break;
        case '3'://新书入库
            this->newbook();
            break;
        case '4'://删除书籍
            this->delbook();
            break;
        case '5'://修改书籍
            this->changebook();
            break;
        case '6'://退出管理员系统
            exit(0);
            break;
        default:
            cout << "无法操作" << endl;
            break;
        }
    }
}

void person::newbook()//管理员添加书籍
{
    
    cout << "请输入图书名称" << endl;
    cin >> bookname;
    cout << "请输入图书内容" << endl;
    cin >> neirong;
    book.insert(make_pair(bookname, neirong));
}


void manager::delbook()//管理员删除书籍
{
    string name;
    cout << "请输入你想删除书籍的名称" << endl;
    cin >> name;
    map<string, string>::iterator qwe = book.find(name);
        if (qwe != book.end())
        {
            book.erase(name);
        }
        else
        {
            cout << "没有该书籍无法删除" << endl;
        }
}


void manager::changebook()//管理员修改图书内容
{
    string changebookname,changebookneirong;
    cout << "请输入你想修改书籍的名称" << endl;
    cin >> changebookname;
    map<string, string>::iterator pos = book.find(changebookname);
    if (pos != book.end())
    {
        cout << "请输入修改后的内容" << endl;
        cin >> changebookneirong;
        book.insert(make_pair(changebookname, changebookneirong));
    }
    else
    {
        cout << "没有该书籍" << endl;
    }

}


void student::change()//学生修改密码
{
    int zhanghao, mima;
    cout << "请输入你的账号" << endl;
    cin >> zhanghao;
    map<int, int>::iterator it = m1.find(zhanghao);
    if (it != m1.end())
    {
        cout << "请输入你想要修改的密码" << endl;
        cin >> mima;
        m1.insert(make_pair(zhanghao, mima));
    }
    else
    {
        cout << "法查询该账号信息请注册或注意输入账号是否正确" << endl;
    }
 }

