This is the corrected version for Clang (12.0.1-19ubuntu3). I encountered a failure with the minus_test due to the older compiler version not handling the ft_strlen(sign) case properly.
