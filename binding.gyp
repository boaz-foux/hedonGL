{
  'variables': {
    'platform': '<(OS)',
  },
  'conditions': [
    ['platform == "mac"', {
      'variables': {
        'platform': 'darwin'
      }
    }],
    ['platform == "win"', {
      'variables': {
        'platform': 'win32'
        }
    }],
  ],
  'targets': [
    {
      'target_name': 'hedonGLsource',
      'defines': [
        'VERSION=0.4.6',
      ],
      'sources': [
        'src/main.cc'
      ],
      'include_dirs': [
        "<!(node -e \"require('hedonh')\")"
      ],
      'conditions': [
        ['OS=="win"', {
            'library_dirs': [
              './deps/windows/lib/<(target_arch)',
              ],
            'libraries': [
              'glfw3dll.lib',
              'glew32.lib',
              'opengl32.lib'
              ]
            }
        ],
        ['OS=="linux"', {
          'libraries': [
            '-lXrandr','-lXinerama','-lXxf86vm','-lXcursor','-lXi',
            '-lrt','-lm'
            ]
        }],
        ['OS=="mac"', {
          # 'include_dirs': [ '<!@(pkg-config glfw3 glew --cflags-only-I | sed s/-I//g)'],
          'libraries': [ '<!@(pkg-config --libs glfw3 glew)', '-framework OpenGL'],
          'library_dirs': ['/usr/local/lib'],
        }],
      ]
    }
  ]
}
