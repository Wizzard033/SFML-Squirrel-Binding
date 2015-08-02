The binding includes the following modules from SFML
* Graphics
* Network
* System
* Window

Here is an example of how to load it up (depends on http://scrat.sourceforge.net/)

    // Initialize and register the sf namespace in the VM
    Sqrat::Table sfNamespace(v);
    Sqrat::RootTable(v).Bind(_SC("sf"), sfNamespace);

    // Initialize and register the SFML system Squirrel libraries in the VM
    RegisterSfmlClockLib(v, sfNamespace);
    RegisterSfmlStringLib(v, sfNamespace);
    RegisterSfmlTimeLib(v, sfNamespace);
    RegisterSfmlVector2Lib(v, sfNamespace);
    RegisterSfmlVector3Lib(v, sfNamespace);

    // Initialize and register the SFML window Squirrel libraries in the VM
    RegisterSfmlEventLib(v, sfNamespace);
    RegisterSfmlJoystickLib(v, sfNamespace);
    RegisterSfmlKeyboardLib(v, sfNamespace);
    RegisterSfmlMouseLib(v, sfNamespace);
    RegisterSfmlStyleLib(v, sfNamespace);
    RegisterSfmlVideoModeLib(v, sfNamespace);

    // Initialize and register the SFML graphics Squirrel libraries in the VM
    RegisterSfmlBlendModeLib(v, sfNamespace);
    RegisterSfmlColorLib(v, sfNamespace);
    RegisterSfmlFontLib(v, sfNamespace);
    RegisterSfmlGlyphLib(v, sfNamespace);
    RegisterSfmlImageLib(v, sfNamespace);
    RegisterSfmlPrimitiveTypeLib(v, sfNamespace);
    RegisterSfmlRectLib(v, sfNamespace);
    RegisterSfmlRenderStatesLib(v, sfNamespace);
    RegisterSfmlRenderTargetLib(v, sfNamespace);
    RegisterSfmlRenderTextureLib(v, sfNamespace);
    RegisterSfmlRenderWindowLib(v, sfNamespace);
    RegisterSfmlTextureLib(v, sfNamespace);
    RegisterSfmlTransformLib(v, sfNamespace);
    RegisterSfmlTransformableLib(v, sfNamespace);
    RegisterSfmlShapeLib(v, sfNamespace);
    RegisterSfmlCircleShapeLib(v, sfNamespace);
    RegisterSfmlConvexShapeLib(v, sfNamespace);
    RegisterSfmlRectangleShapeLib(v, sfNamespace);
    RegisterSfmlSpriteLib(v, sfNamespace);
    RegisterSfmlTextLib(v, sfNamespace);
    RegisterSfmlVertexLib(v, sfNamespace);
    RegisterSfmlVertexArrayLib(v, sfNamespace);
    RegisterSfmlViewLib(v, sfNamespace);

    // Initialize and register the SFML network Squirrel libraries in the VM
    RegisterSfmlIpAddressLib(v, sfNamespace);
    RegisterSfmlPacketLib(v, sfNamespace);
    RegisterSfmlPortLib(v, sfNamespace);
    RegisterSfmlSocketLib(v, sfNamespace);
    RegisterSfmlTcpListenerLib(v, sfNamespace);
    RegisterSfmlTcpSocketLib(v, sfNamespace);
    RegisterSfmlUdpSocketLib(v, sfNamespace);


** This binding will not be maintained by its developer, but merge requests will be reviewed **
