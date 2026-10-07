#pragma once
// Game 2: Hangman

#include <string>

namespace hangman {
// ==========================================
    // الجزء الثاني: إدخال المستخدم والتحقق (الشخص 2)
    // ==========================================
    // قراءة حرف من المستخدم مع التحقق من صحته ورفض التكرار
    char readValidLetter(const std::vector<char>& alreadyGuessed);
} 
