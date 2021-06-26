QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    include/ \
    include/box2d/ \
    src/ \
    src/dynamics/


SOURCES += \
    balken.cpp \
    ball.cpp \
    button.cpp \
    counter.cpp \
    feder.cpp \
    foehn.cpp \
    game.cpp \
    info.cpp \
    level.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    main.cpp \
    maske.cpp \
    src/collision/b2_broad_phase.cpp \
    src/collision/b2_chain_shape.cpp \
    src/collision/b2_circle_shape.cpp \
    src/collision/b2_collide_circle.cpp \
    src/collision/b2_collide_edge.cpp \
    src/collision/b2_collide_polygon.cpp \
    src/collision/b2_collision.cpp \
    src/collision/b2_distance.cpp \
    src/collision/b2_dynamic_tree.cpp \
    src/collision/b2_edge_shape.cpp \
    src/collision/b2_polygon_shape.cpp \
    src/collision/b2_time_of_impact.cpp \
    src/common/b2_block_allocator.cpp \
    src/common/b2_draw.cpp \
    src/common/b2_math.cpp \
    src/common/b2_settings.cpp \
    src/common/b2_stack_allocator.cpp \
    src/common/b2_timer.cpp \
    src/dynamics/b2_body.cpp \
    src/dynamics/b2_chain_circle_contact.cpp \
    src/dynamics/b2_chain_polygon_contact.cpp \
    src/dynamics/b2_circle_contact.cpp \
    src/dynamics/b2_contact.cpp \
    src/dynamics/b2_contact_manager.cpp \
    src/dynamics/b2_contact_solver.cpp \
    src/dynamics/b2_distance_joint.cpp \
    src/dynamics/b2_edge_circle_contact.cpp \
    src/dynamics/b2_edge_polygon_contact.cpp \
    src/dynamics/b2_fixture.cpp \
    src/dynamics/b2_friction_joint.cpp \
    src/dynamics/b2_gear_joint.cpp \
    src/dynamics/b2_island.cpp \
    src/dynamics/b2_joint.cpp \
    src/dynamics/b2_motor_joint.cpp \
    src/dynamics/b2_mouse_joint.cpp \
    src/dynamics/b2_polygon_circle_contact.cpp \
    src/dynamics/b2_polygon_contact.cpp \
    src/dynamics/b2_prismatic_joint.cpp \
    src/dynamics/b2_pulley_joint.cpp \
    src/dynamics/b2_revolute_joint.cpp \
    src/dynamics/b2_weld_joint.cpp \
    src/dynamics/b2_wheel_joint.cpp \
    src/dynamics/b2_world.cpp \
    src/dynamics/b2_world_callbacks.cpp \
    src/rope/b2_rope.cpp \
    uhr.cpp \
    virus.cpp

HEADERS += \
    balken.h \
    ball.h \
    button.h \
    counter.h \
    definitions.h \
    element.h \
    feder.h \
    foehn.h \
    game.h \
    include/box2d/b2_api.h \
    include/box2d/b2_block_allocator.h \
    include/box2d/b2_body.h \
    include/box2d/b2_broad_phase.h \
    include/box2d/b2_chain_shape.h \
    include/box2d/b2_circle_shape.h \
    include/box2d/b2_collision.h \
    include/box2d/b2_common.h \
    include/box2d/b2_contact.h \
    include/box2d/b2_contact_manager.h \
    include/box2d/b2_distance.h \
    include/box2d/b2_distance_joint.h \
    include/box2d/b2_draw.h \
    include/box2d/b2_dynamic_tree.h \
    include/box2d/b2_edge_shape.h \
    include/box2d/b2_fixture.h \
    include/box2d/b2_friction_joint.h \
    include/box2d/b2_gear_joint.h \
    include/box2d/b2_growable_stack.h \
    include/box2d/b2_joint.h \
    include/box2d/b2_math.h \
    include/box2d/b2_motor_joint.h \
    include/box2d/b2_mouse_joint.h \
    include/box2d/b2_polygon_shape.h \
    include/box2d/b2_prismatic_joint.h \
    include/box2d/b2_pulley_joint.h \
    include/box2d/b2_revolute_joint.h \
    include/box2d/b2_rope.h \
    include/box2d/b2_settings.h \
    include/box2d/b2_shape.h \
    include/box2d/b2_stack_allocator.h \
    include/box2d/b2_time_of_impact.h \
    include/box2d/b2_time_step.h \
    include/box2d/b2_timer.h \
    include/box2d/b2_types.h \
    include/box2d/b2_weld_joint.h \
    include/box2d/b2_wheel_joint.h \
    include/box2d/b2_world.h \
    include/box2d/b2_world_callbacks.h \
    include/box2d/box2d.h \
    info.h \
    level.h \
    level1.h \
    level2.h \
    level3.h \
    maske.h \
    src/dynamics/b2_chain_circle_contact.h \
    src/dynamics/b2_chain_polygon_contact.h \
    src/dynamics/b2_circle_contact.h \
    src/dynamics/b2_contact_solver.h \
    src/dynamics/b2_edge_circle_contact.h \
    src/dynamics/b2_edge_polygon_contact.h \
    src/dynamics/b2_island.h \
    src/dynamics/b2_polygon_circle_contact.h \
    src/dynamics/b2_polygon_contact.h \
    uhr.h \
    virus.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
