# Python��C++�̋��n��

## numpy��g�ݍ��킹�����p���@
�ȉ���Qiita�̋L�����ۃR�s�B�L���ɂ�Visual Studio��Debuger�������Ȃ��Ƃ��������Adebug���̃p�X�̌�F�����H$(ProjectDir)�ɓǂݍ��ݑΏۂ�python�X�N���v�g��u���ƃf�o�b�O�ł���B  
[C++ ���� Numpy�t Boost ����� Python���Ă� �iVisual Studio 2017 �Ή��j](https://qiita.com/SatoshiTerasaki/items/03e5d9b6a1c353d7273b)

## Boost�̃r���h
boost_1_72�Ŋm�F  
�_�E�����[�h�Ɖ𓀂����\���Ԃ�������̂Œ���

user-config.jam��anaconda��python��.exe��libs��include���w�肵�� *--with-python* ��t����b2.exe�����s����B  

c++�̃R�[�h��visual studio�Ńr���h�����Ƃ��Ɉȉ��̃G���[�����������B  
> �d��x���x��	�R�[�h	����	�v���W�F�N�g	�t�@�C��	�s	�}�����
�G���[	LNK1181	���̓t�@�C�� 'libboost_python36-vc142-mt-sgd-x64-1_72.obj' ���J���܂���B	PyLib	C:\Users\yshira\Work\VAR\src\PyLib\PyLib\LINK	1	  

�r���h�ς݂�boost���C�u�����������sgd����Ȃ���gd�Ȃ炠�����Bsgd��gd�̈Ⴂ��runtime-link��shared��static���̈Ⴂ�炵���BRuntime-link=static�ɂ��čēxb2�����s��������������B


```cmd
REM ���s�������e�͂���Ȋ����B
> cd $(PATH_TO_BOOST_SRC)
>.\bootstrap.bat
>vim tools\build\src\user-config.jam
>.\b2 toolset=msvc-14.2 variant=debug,release runtime-link=static,shared link=static --build-type=complete stage --abbreviate-paths architecture=x86 address-model=64 install -j6 --with-python
```

[user-config.jam�ɂ���](https://stackoverflow.com/questions/30379543/not-able-to-find-user-config-jam-while-installing-boost-libraries)  
[python�p�X�̐ݒ���@](https://github.com/boostorg/build/issues/194#issuecomment-299030791)


# 