//http://segafreder.hatenablog.com/entry/2016/12/18/110423
//https://qiita.com/SatoshiTerasaki/items/03e5d9b6a1c353d7273b

#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <list>


#define MAX_X 100 //�󂯓n�������s��̃T�C�Y�B

namespace np = boost::python::numpy;

int main() {

    //Python�Anumpy���W���[���̏�����
    Py_Initialize();
    np::initialize();

    //���O��Ԃ̊m��
    auto main_ns = boost::python::import("__main__").attr("__dict__");

    //Python�X�N���v�g�̓ǂݍ���
    std::ifstream ifs("mat_numpy.py");
    std::string script((std::istreambuf_iterator<char>(ifs)),
        std::istreambuf_iterator<char>());

    //100x100�s��̏���
    boost::python::tuple shapeA = boost::python::make_tuple(MAX_X, MAX_X);
    np::ndarray A = np::zeros(shapeA, np::dtype::get_builtin<double>());
    for (int i = 0; i != MAX_X; i++) {
        for (int j = 0; j != MAX_X; j++) {
            A[i][j] = i + j;
        }
    }

    //mat_numpy.mul�̎��s
    boost::python::exec(script.c_str(), main_ns);
    auto func = main_ns["mul"];
    auto pyresult_numpy = func(A);

    //���ʂ̎󂯎��
    //stl_input_iterator���g���ă^�v���S�v�f���󂯎��
    boost::python::stl_input_iterator<np::ndarray> begin(pyresult_numpy), end;
    std::list<np::ndarray> pyresult_list(begin, end);

    for (auto itr = pyresult_list.begin(); itr != pyresult_list.end(); ++itr) {
        double* p = reinterpret_cast<double*>((*itr).get_data());
        //ndarray�ł͊�{�I�Ƀ������͘A���̈��ɕێ������̂ŁA
        //�e�v�f�ɂ�[]���Z�q���g���ăA�N�Z�X�ł���
        std::cout << p[0] << ',' << p[1] << ',' << p[2] << ',' << p[MAX_X * MAX_X - 1] << std::endl;
    }
    return 0;
}
