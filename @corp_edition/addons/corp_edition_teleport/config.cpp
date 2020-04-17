class CfgPatches {
  class CORP_Edition_Teleport {
    units[] = {"CORP_Module_Teleport"};
    author = "CORP Modding Studio";
    requiredVersion = 1.98;
    requiredAddons[] = {"A3_Modules_F", "corp_edition_core"};
  };
};

class CfgFunctions {
  class CORP {
    tag = "CORP";

    class CORPEditionTeleport {
      file = "\corp_edition_teleport\functions";
      class Teleport_Init {};
      class Teleport_UiStart {};
    };
  };
};

class CfgVehicles {
  class Logic;
  class Module_F: Logic {
    class AttributesBase {
      class Edit;
    };
    class ModuleDescription {
      class AnyStaticObject;
    };
  };

  class CORP_Module_Teleport: Module_F {
    scope = 2;
    displayName = $STR_CORP_TELEPORT_DN;
    icon = "\corp_edition_teleport\icon.paa";
    category = "CORP_Modules";

    function = "CORP_fnc_teleport_init";
    functionPriority = 1;
    isGlobal = 1;
    isTriggerActivated = 0;
    isDisposable = 0;
    is3DEN = 0;

    class Attributes: AttributesBase {
      class ModuleDescription: ModuleDescription{};

      class ActionText: Edit {
          property = "CORP_Module_Teleport_ActionText";
          displayName = $STR_CORP_TELEPORT_ACTION_TEXT_DN;
          tooltip = $STR_CORP_TELEPORT_ACTION_TEXT_TOOLTIP;
          typeName = "STRING";
          defaultValue = """"""; // Empty
      };

      class ActionDistance: Edit {
          property = "CORP_Module_Teleport_ActionDistance";
          displayName = $STR_CORP_TELEPORT_ACTION_DISTANCE_DN;
          tooltip = $STR_CORP_TELEPORT_ACTION_DISTANCE_TOOLTIP;
          typeName = "NUMBER";
          defaultValue = "5";
          control = "SliderAddactionDistance";
      };
    };

    class ModuleDescription: ModuleDescription {
      description = $STR_CORP_TELEPORT_DESC;
      sync[] = {"AnyStaticObject"};
    };
  };
};

#include "ui\ui.hpp"
