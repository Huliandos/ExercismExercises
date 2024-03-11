#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H

#include <vector>
#include <string>

namespace secret_handshake {
    std::vector<std::string> commands(int);

    void reverseVector(std::vector<std::string>&);
}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
