class CfgPatches {
    class CORP_Edition_Teleport_To_Position {
        units[] = {"CORP_Module_TeleportToPosition"};
        author = "CORP Modding Studio";
        requiredVersion = 1.98;
        requiredAddons[] = {"A3_Modules_F", "corp_edition_core"};
    };
};

class CfgFunctions {
    class CORP {
        tag = "CORP";

        class CORPEditionTeleportToPosition {
            file = "\corp_edition_teleport_to_position\functions";
            class TeleportToPosition_Init {};
        };
    };
};

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Edit;
            class CategoryDescription {
              control = "SubCategoryNoHeader1";
              data = "AttributeSystemSubcategory";
            };
        };

        class ModuleDescription {
            class AnyStaticObject;
        };
    };

    class CORP_Module_TeleportToPosition: Module_F {
        scope = 2;
        displayName = $STR_CORP_TELEPORT_TO_POSITION_DN;
        icon = "\corp_edition_teleport_to_position\icon.paa";
        category = "CORP_Modules";

        function = "CORP_fnc_teleportToPosition_init";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;

        class Attributes: AttributesBase {
            class ModuleDescription: ModuleDescription {};

            class ActionCategoryDescription: CategoryDescription {
              description = $STR_CORP_TELEPORT_TO_POSITION_ACTION_CATEGORY;
            };

            class ActionText: Edit {
                property = "CORP_Module_TeleportToPosition_ActionText";
                displayName = $STR_CORP_TELEPORT_TO_POSITION_ACTION_TEXT_DN;
                tooltip = $STR_CORP_TELEPORT_TO_POSITION_ACTION_TEXT_TOOLTIP;
                typeName = "STRING";
                defaultValue = """Action""";
            };

            class ActionDistance: Edit {
                property = "CORP_Module_TeleportToPosition_ActionDistance";
                displayName = $STR_CORP_TELEPORT_TO_POSITION_ACTION_DISTANCE_DN;
                tooltip = $STR_CORP_TELEPORT_TO_POSITION_ACTION_DISTANCE_TOOLTIP;
                typeName = "NUMBER";
                defaultValue = "5";
                control = "SliderAddactionDistance";
            };

            class TeleportCategoryDescription: CategoryDescription {
              description = $STR_CORP_TELEPORT_TO_POSITION_TELEPORT_CATEGORY;
            };

            class TeleportPosition: Edit {
                property = "CORP_Module_TeleportToPosition_TeleportPosition";
                displayName = $STR_CORP_TELEPORT_TO_POSITION_TELEPORT_POSITION_DN;
                tooltip = $STR_CORP_TELEPORT_TO_POSITION_TELEPORT_POSITION_TOOLTIP;
                typeName = "STRING";
                defaultValue = """[0, 0, 0]""";
            };

            class TeleportDirection: Edit {
                property = "CORP_Module_TeleportToPosition_TeleportDirection";
                displayName = $STR_CORP_TELEPORT_TO_POSITION_TELEPORT_DIRECTION_DN;
                tooltip = $STR_CORP_TELEPORT_TO_POSITION_TELEPORT_DIRECTION_TOOLTIP;
                typeName = "NUMBER";
                defaultValue = "0";
            };
        };

        class ModuleDescription: ModuleDescription {
          description = $STR_CORP_TELEPORT_TO_POSITION_DESC;
          sync[] = {"AnyStaticObject"};
        };
    };
};
