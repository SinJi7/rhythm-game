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
    //사용 노트
    std::vector<Common_note> used_note;
    std::vector<Long_note> used;

    //미사용 노트
    std::vector<Common_note> not_used_note;
    std::vector<Long_note> not_usedd_note;

    loadFile(std::string name); //노트 파일 로딩 미사용 노트 기본


    public:
    NoteFile(std::string name);//생성자
    ~NoteFile();
    
    search_note(time_t time); //현재 시간 일정 범위 이내 노드 탐색


#endif