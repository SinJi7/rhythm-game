#ifndef NOTE_File_H
#define NOTE_File_H

#include <fstream>
#include <vector>
#include "Note.h"
#include <string>
#include <time.h>

class NoteFile
{
    private:
    FILE notefile;
    //상대 시간 노드, 절대 시간 아님

    note::Note_List base_node; //런타임에 로딩시, 동적할당

    loadFile(std::string name); //노트 파일 로딩 미사용 노트 기본


    public:
    NoteFile(std::string name);//생성자
    ~NoteFile();

    //게임로딩시 노드들 절대시간으로 변환한다.
    void Note_Convert(note::Note_List* p_nls_gamenote);


#endif