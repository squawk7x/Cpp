std::string makePattern(int digit, int length, std::string opaque,
                        std::string translucent) {
    std::string pattern = "";

    for (int i = 0; i < digit; i++) {
        pattern += opaque;
    }

    for (int i = digit; i < length; i++) {
        pattern += translucent;
    }

    return pattern;
}