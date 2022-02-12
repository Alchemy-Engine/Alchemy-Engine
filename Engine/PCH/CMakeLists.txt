SET(PCH)

ADD_LIBRARY( PCH STATIC
    pch.cc
)

target_precompile_headers(PCH PUBLIC
    pch.h
)